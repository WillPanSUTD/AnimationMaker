#ifndef ANIMATIONSCENE_H
#define ANIMATIONSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDataStream>
#include <QGraphicsItem>
#include <QTest>
#include <QFileDialog>

#include "resizeableitem.h"

class AnimationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    AnimationScene();

    enum ItemType { TypeItem, TypeRectangle, TypeEllipse, TypeText, TypeBitmap, TypeSvg };
    enum EditMode { ModeSelect, ModeRectangle, ModeEllipse, ModeText, ModeBitmap, ModeSvg };

    void setEditMode(EditMode mode);
    QDataStream& read(QDataStream &dataStream);
    QDataStream& write(QDataStream &dataStream) const;

signals:
    void itemAdded(QGraphicsItem *item);
    void itemSelectionChanged(ResizeableItem *item);
    void addPropertyAnimation(ResizeableItem *item, const QString propertyName, qreal value);

public slots:
    void addPropertyAnimationRequested(ResizeableItem *item, const QString propertyName, qreal value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
    EditMode m_editMode;
};

QDataStream &operator<<(QDataStream &, const AnimationScene *);
QDataStream &operator>>(QDataStream &, AnimationScene *);
QString getItemTypeName(QGraphicsItem *item);
bool isAnimationMakerItem(QGraphicsItem *item);

#endif // ANIMATIONSCENE_H
