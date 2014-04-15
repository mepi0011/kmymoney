/*
 * This file is part of KMyMoney, A Personal Finance Manager for KDE
 * Copyright (C) 2014 Christian Dávid <christian-david@web.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INTERNATIONALACCOUNTIDENTIFIER_H
#define INTERNATIONALACCOUNTIDENTIFIER_H

#include <QtCore/QString>
#include <QtCore/QChar>

#include "payeeidentifier/payeeidentifier.h"

#include "ibanbicmacros.h"

class ibanBicData;

/**
 * @brief Plugin to handle IBANs and BICs
 * 
 * Can store a pair of an International Bank Account Number (ISO 13616) and Business Identifier Code (ISO 9362).
 * 
 * With it's own plugins (@ref KMyMoneyPlugin::ibanBicPlugin) futher information can be accessed.
 */
class IBAN_BIC_IDENTIFIER_EXPORT internationalAccountIdentifier : public payeeIdentifier
{
  KMM_UNIT_TESTABLE
public:
  PAYEEIDENTIFIER_ID(internationalAccountIdentifier, "org.kmymoney.payeeIdentifier.ibanbic");
  
  internationalAccountIdentifier();
  internationalAccountIdentifier(const internationalAccountIdentifier& other);
  
  internationalAccountIdentifier* clone() const;
  internationalAccountIdentifier* createFromXml(const QDomElement& element) const;
  void writeXML(QDomDocument& document, QDomElement& parent) const;
  
  /**
   * @brief Set a IBAN
   * 
   * The IBAN can contain spaces and other special chars.
   */
  void setIban( const QString& iban );

  /** @copydoc m_iban
   * Use this method if you know that iban is in electronic format already. No futher checks are done.
   */
  void setElectronicIban( const QString& iban ) { Q_ASSERT( iban == ibanToElectronic(iban) ); m_iban = iban; }

  /** @copydoc m_iban */
  QString electronicIban() const { return m_iban; }
  
  /**
   * @brief Returns iban in human readable format
   * @see toPaperformatIban()
   */
  QString paperformatIban( const QString& seperator = QLatin1String(" ") ) const;
  
  /**
   * @brief Set Business Identifier Code
   * 
   * Call without parameter or QString() to remove bic
   * 
   * @param bic will be normalized
   */
  void setBic( const QString& bic = QString() );
  
  /**
   * @brief Business Identifier Code
   * According to ISO 9362
   * 
   * The returned bic is normalized:
   * A tailing XXX is omitted, all characters are uppercase.
   */
  QString storedBic() const { return m_bic; }
  
  /**
   * @copydoc storedBic()
   * 
   * Return a stored BIC (if there is any) or try to use the iban to get a BIC.
   */
  QString bic() const;
  
  /**
   * @brief Business Identifier Code with tailing XXX
   * 
   * Like @a bic() but always 11 characters long (if bic is invalid, it can have another length).
   */
  QString fullBic() const;
  
  /**
   * @copydoc fullBic()
   * 
   * This method will not try to use the iban to get a bic.
   */
  QString fullStoredBic() const;
  
  
  virtual bool operator==(const payeeIdentifier& other) const;
  bool operator==(const internationalAccountIdentifier& other) const;
  virtual bool isValid() const;
  
  /**
   * @brief Converts an iban to canonical format for machines
   * 
   * Will remove all white spaces.
   */
  static QString ibanToElectronic( const QString& iban );
  
  /**
   * @brief Converts an iban to human readable format
   * 
   * Grouped in four letters strings seperated by a white space.
   * 
   * @param iban an iban, not needed to be canonical, valid or completed
   * @param seperator Overwrite the default seperator (e.g. a smaller space)
   */
  static QString ibanToPaperformat( const QString& iban, const QString& seperator = QLatin1String(" ") );
  
  /**
   * @brief Extract Basic Bank Account Number
   * 
   * Returns the Basic Bank Account Number (BBAN) from the IBAN.
   * The BBAN is the IBAN without country code and the two digit checksum.
   */
  static QString bban( const QString& iban );
  
  static int ibanLengthByCountry( const QString& countryCode );
  
  static QString institutionNameByBic( const QString& bic );
  
  static QString bicByIban( const QString& iban );
  
  static QString localBankCodeByIban( const QString& iban );
  
  static const int ibanMaxLength;
  
private:
  /**
   * @brief Business Identifier Code
   * According to ISO 9362
   * 
   * A tailing XXX must be ommited. All characters must be upper case.
   */
  QString m_bic;
  
  /**
   * @brief  International Bank Account Number
   * According to ISO 13616-1:2007 Part 1
   * in normalized (electronic) format (no spaces etc.)
   */
  QString m_iban;
  
  static ::ibanBicData* m_ibanBicData;
};

#endif // INTERNATIONALACCOUNTIDENTIFIER_H

