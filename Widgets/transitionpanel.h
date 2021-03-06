/****************************************************************************
** Copyright (C) 2016 Olaf Japp
**
** This file is part of AnimationMaker.
**
**  AnimationMaker is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  AnimationMaker is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef TRANSITIONPANEL_H
#define TRANSITIONPANEL_H

#include <QWidget>
#include <QModelIndex>
#include <QTreeWidget>
#include <QVBoxLayout>
#include "transitionline.h"
#include "widgets_global.h"

class Timeline;
class QUndoStack;
class WIDGETSSHARED_EXPORT TransitionPanel : public QWidget
{
    Q_OBJECT
public:
    TransitionPanel(QUndoStack *undostack);

    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent *);
    void setTreeWidget(QTreeWidget *tv);
    void reset();
    void setPlayheadPosition(int value);
    void removeItem(AnimationItem *item);
    inline void registerTimeline(Timeline *timeline) {m_timeline = timeline;}
    void transitionAdded(AnimationItem *item, QString propertyName, KeyFrame *key);
    void transitionDeleted(AnimationItem *item, QString propertyName, KeyFrame *key);
    void keyframeMoved(KeyFrame *key);
    void transitionMoved(KeyFrame *key);
    void transitionResized(KeyFrame *key);
    void addTransition(AnimationItem *item, QString propertyName, KeyFrame *key);
    void deleteTransition(AnimationItem *item, QString propertyName, KeyFrame *key);

public slots:
    void treeExpanded(QModelIndex);
    void treeCollapsed(QModelIndex);
    void treeScrollValueChanged(int);
    void lineAdded(AnimationItem *item);
    void propertyAdded(AnimationItem *item, QString propertyName);
    void propertyKeyAdded(AnimationItem *item, QString propertyName, KeyFrame *key);
    void propertyKeyRemoved(AnimationItem *item, QString propertyName, KeyFrame *key);
    void deleteKeyframe(AnimationItem *item, QString propertyName);
    void scrollValueChanged(int pos);
    void transitionSelected(KeyFrame *frame);

private:
    int m_verticalScrollPos;
    int m_horizontalScrollPos;
    QTreeWidget *m_tree;
    QVBoxLayout *m_layout;
    Timeline *m_timeline;
    int m_playheadPosition;
    QUndoStack *m_undostack;

    void enableDisableLines();
#ifdef TEST
public:
#endif
    TransitionLine *getTransitionLine(AnimationItem *item, QString propertyName);
};

#endif // TRANSITIONPANEL_H
