// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#ifndef QMOMTREECUSTOMEXTENSIONS_H
#define QMOMTREECUSTOMEXTENSIONS_H

class QMoMTreeCustomExtensions
{
public:
    QMoMTreeCustomExtensions();

    bool load(const QString& filename);
//    void update(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row);
};

#endif // QMOMTREECUSTOMEXTENSIONS_H
