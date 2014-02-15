/*
 * This file is part of KMyMoney, A Personal Finance Manager for KDE
 * Copyright (C) 2013 Christian Dávid <christian-david@web.de>
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

#include "onlinetask.h"

onlineTask::onlineTask()
{}

onlineTask::onlineTask(const onlineTask &other)
{
  Q_UNUSED(other);
}

/**void onlineJob::setState( jobState new_state )
{
  m_state = new_state;
}*/

onlineTask::settings::~settings()
{}

void onlineTask::writeXML(QDomDocument &document, QDomElement &parent) const
{
  Q_UNUSED(document);
  Q_UNUSED(parent);
}
