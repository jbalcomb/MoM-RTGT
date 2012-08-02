// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <QtXml>

#include "QMoMTreeCustomExtensions.h"

namespace
{

class Handler : public QXmlDefaultHandler
{

};

}

QMoMTreeCustomExtensions::QMoMTreeCustomExtensions()
{
}

bool QMoMTreeCustomExtensions::load(const QString &filename)
{
    bool ok = true;
    QXmlSimpleReader xmlReader;
    QFile* file = new QFile(filename);
    QXmlInputSource* source = new QXmlInputSource(file);
    Handler* handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);

    ok = xmlReader.parse(source);
    if (ok)
    {
        qDebug() << "Parsed " << filename;
    }
    else
    {
        qDebug() << "Failed to parse " << filename;
    }

    delete handler;
    delete source;
    delete file;

    return ok;
}

//void QMoMTreeCustomExtensions::update(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row)
//{
//    if (0 == game)
//        return;
//    MoM::Battle_Unit* pBattle_Unit_View = game->getBattle_Unit_View();
//    if (0 == pBattle_Unit_View)
//        return;

//    if (row >= ptree->rowCount())
//    {
//        ptree->setChild(row, 0, constructTreeItem(pBattle_Unit_View, ""));
//    }
//    QString id;
//    int unitNr = pBattle_Unit_View->m_unitNr;
//    if ((unitNr >= 0) && (unitNr < game->getNrUnits()) && (unitNr < (int)MoM::gMAX_UNITS))
//    {
//        MoM::Unit* unit = game->getUnit(unitNr);
//        if (0 != unit)
//        {
//            id = toQStr(unit->m_Unit_Type);
//        }
//    }
//    else
//    {
//        id = toQStr(pBattle_Unit_View->m_Race_Code);
//    }
//    ptree->child(row, 0)->setData(id, Qt::UserRole);
//    ptree->child(row, 1)->setData(toQStr(pBattle_Unit_View->m_Owner), Qt::UserRole);
//    ptree->child(row, 2)->setData(QString(), Qt::EditRole);

//    ++row;
//}
