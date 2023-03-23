#include "moveitem.h"
#include <QDebug>


MoveItem::MoveItem(QObject *parent) :
  QObject(parent), QGraphicsItem()
{
}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
  return QRectF (-10,-10,70,70);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(Qt::black);
  painter->setBrush(Qt::green);
  painter->drawRect(0,0,3,63);

  Q_UNUSED(option);
  Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  this->setPos(mapToScene(event->pos().x(),0));
  if (pressed){
      QPointF newPos = event->scenePos();

      //qDebug()<<newPos;
      int yDiff = newPos.y() - oldPos.y();
      //qDebug()<<abs(yDiff);
      int heightDiff=15;
      if (abs(yDiff) > heightDiff ){
          heightDiff*=2;
          heightDiff+=5;
          //int d = (int)(yDiff%heightDiff);
          newPos.setY(oldPos.y()+(int)(yDiff/heightDiff)*heightDiff);//*((int)(yDiff/30))>0?1:0);
          //setY(newPos.y());
          //                tempOldPos.setY(newPos.y() - oldPos.y());
        }else{
          //setY(oldPos.y());
        }


      //            setPos(pos() +newPos-tempOldPos);
      int dx = (newPos - oldMousePos).x();
      setX(oldPos.x()+dx);
      pos=oldPos.x()+dx;
      //qDebug()<<"class move "<<oldPos.x()+dx;
       //getXpos();

    }
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{    this->setCursor(QCursor(Qt::ClosedHandCursor));
     Q_UNUSED(event);
     //qDebug()<<"Press";
        pressed = true;
        oldMousePos = event->scenePos();
        oldPos = scenePos();
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{    this->setCursor(QCursor(Qt::ArrowCursor));
     Q_UNUSED(event);
}
void MoveItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{    this->setCursor(QCursor(Qt::ArrowCursor));
     Q_UNUSED(event);
     //getXpos();
     qDebug()<<"dobleclick";
}
