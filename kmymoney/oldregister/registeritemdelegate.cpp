/*
 * Copyright 2006-2018  Thomas Baumgart <tbaumgart@kde.org>
 * Copyright 2017-2018  Łukasz Wojniłowicz <lukasz.wojnilowicz@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "registeritemdelegate.h"

// ----------------------------------------------------------------------------
// QT Includes

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// Project Includes

#include "register.h"
#include "registeritem.h"

/// @todo remove this class with old register code
using namespace KMyMoneyRegister;

RegisterItemDelegate::RegisterItemDelegate(Register *parent) :
  QStyledItemDelegate(parent),
  m_register(parent)
{
}

RegisterItemDelegate::~RegisterItemDelegate()
{
}

void RegisterItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  RegisterItem* const item = m_register->itemAtRow(index.row());
  if (item && m_register->updatesEnabled()) {
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);
    item->paintRegisterCell(painter, opt, index);
  }
}
