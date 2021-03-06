/***************************************************************************
                         checkingstatementinfowizardpage.cpp  -  description
                            -------------------
   begin                : Sun Jul 18 2010
   copyright            : (C) 2010 by Fernando Vilas
   email                : kmymoney-devel@kde.org
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "checkingstatementinfowizardpage.h"

// ----------------------------------------------------------------------------
// QT Includes

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// Project Includes

#include "ui_checkingstatementinfowizardpage.h"

CheckingStatementInfoWizardPage::CheckingStatementInfoWizardPage(QWidget *parent) :
  QWizardPage(parent),
  ui(new Ui::CheckingStatementInfoWizardPage)
{
  ui->setupUi(this);
  ui->m_statementDate->setDate(QDate::currentDate());

  // Register the fields with the QWizard and connect the
  // appropriate signals to update the "Next" button correctly
  registerField("statementDate", ui->m_statementDate, "date", SIGNAL(dateChanged(QDate)));

  registerField("endingBalance", ui->m_endingBalance, "value", SIGNAL(textChanged()));
  registerField("endingBalanceValid", ui->m_endingBalance, "valid", SIGNAL(textChanged()));
  registerField("previousBalance", ui->m_previousBalance, "value", SIGNAL(textChanged()));
  registerField("previousBalanceValid", ui->m_previousBalance, "valid", SIGNAL(textChanged()));
}

CheckingStatementInfoWizardPage::~CheckingStatementInfoWizardPage()
{
  delete ui;
}

