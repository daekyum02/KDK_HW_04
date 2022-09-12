#ifndef SHAPE_H
#define SHAPE_H
#include <QMainwindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QDialog>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "mainwindow.h"

class shape
{
public:
    shape();
        virtual void draw()
    {

    }
    virtual void rotation()
    {

    }
};

class rectangle : shape
{
    public:
    int recx,recy;
    QGraphicsRectItem*rectangle1;

     void draw(QGraphicsScene *s,QGraphicsRectItem*r)
      {
          r=s->addRect(0,0,50,50,QPen(Qt::green, 3));
          r->setPen(QPen(Qt::black, 3));
          r->setFlag(QGraphicsItem::ItemIsSelectable);
          r->setBrush(QBrush(Qt::green));
      }
         MainWindow m;
     void rotate(QGraphicsItem * returnrec123,int vlaue)
     {
         QGraphicsItem * item = returnrec123;
         QTransform transform = item->transform();
         transform.rotate(vlaue);
         item->setTransform(transform);
     }

     void move(QGraphicsItem * returnrec123,int x,int y)
     {
         QGraphicsItem * item = returnrec123;
         QTransform transform = item->transform();
         transform.translate(x,y);
         item->setTransform(transform);
     }
};

class triangle : shape
{
    public:
    int trix,trix1,triy;
     QGraphicsPolygonItem *triangle1;
    void draw(QGraphicsScene *s,QGraphicsPolygonItem*t)
    {
     QPolygonF tri1;
     tri1.append(QPointF(-50,0));
     tri1.append(QPointF(0,-50));
     tri1.append(QPointF(50,0));
     t=s->addPolygon(tri1,QPen(Qt::black,2),QBrush(Qt::white));
     t->setPen(QPen(Qt::green, 3));
     t->setFlag(QGraphicsItem::ItemIsSelectable);
     t->setBrush(QBrush(Qt::white));
    }
    void rotate(QGraphicsItem * returnrec123,int vlaue)
    {
        QGraphicsItem * item = returnrec123;
        QTransform transform = item->transform();
        transform.rotate(vlaue);
        item->setTransform(transform);
    }
    void move(QGraphicsItem * returnrec123,int x,int y)
    {
        QGraphicsItem * item = returnrec123;
        QTransform transform = item->transform();
        transform.translate(x,y);
        item->setTransform(transform);

    }
};

class circle :  shape
{
    public:
    QGraphicsEllipseItem *circle1;
    QGraphicsItem *getSelectedItem();
void draw(QGraphicsScene *s,QGraphicsEllipseItem*c)
{
    c=s->addEllipse(0,0,100,100,QPen(Qt::green, 3));
    c->setPen(QPen(Qt::black, 3));
    c->setFlag(QGraphicsItem::ItemIsSelectable);
    c->setBrush(QBrush(Qt::white));
}
void rotate(QGraphicsItem * returnrec123,int vlaue)
{
    QGraphicsItem * item = returnrec123;
    QTransform transform = item->transform();
    transform.rotate(vlaue);
    item->setTransform(transform);
}
void move(QGraphicsItem * returnrec123,int x,int y)
{
    QGraphicsItem * item = returnrec123;
    QTransform transform = item->transform();
    transform.translate(x,y);
    item->setTransform(transform);
}

};

#endif // SHAPE_H
