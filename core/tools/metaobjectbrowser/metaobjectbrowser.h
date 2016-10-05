/*
  metaobjectbrowser.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Kevin Funk <kevin.funk@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_METAOBJECTBROWSER_METATYPEBROWSER_H
#define GAMMARAY_METAOBJECTBROWSER_METATYPEBROWSER_H

#include "toolfactory.h"

QT_BEGIN_NAMESPACE
class QAbstractProxyModel;
class QItemSelection;
QT_END_NAMESPACE

namespace GammaRay {
class PropertyController;

class MetaObjectBrowser : public QObject
{
    Q_OBJECT

public:
    explicit MetaObjectBrowser(ProbeInterface *probe, QObject *parent = 0);

public Q_SLOTS:
    void rescanMetaTypes();

private Q_SLOTS:
    void objectSelected(const QItemSelection &selection);
    void objectSelected(QObject *obj);
    void objectSelected(void *obj, const QString &typeName);

private:
    void metaObjectSelected(const QMetaObject *mo);

    PropertyController *m_propertyController;
    QAbstractProxyModel *m_model;
};

class MetaObjectBrowserFactory : public QObject,
    public StandardToolFactory<QObject, MetaObjectBrowser>
{
    Q_OBJECT
    Q_INTERFACES(GammaRay::ToolFactory)

public:
    explicit MetaObjectBrowserFactory(QObject *parent)
        : QObject(parent)
    {
    }

    QVector<QByteArray> selectableTypes() const Q_DECL_OVERRIDE;
};
}

#endif // GAMMARAY_METAOBJECTBROWSER_METATYPEBROWSER_H
