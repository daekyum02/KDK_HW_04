#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include <QGraphicsView>
#include <QDialog>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),rotation_angle(0)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->addLine(-268,0,268,0,QPen(Qt::black));
    scene->addLine(0,-264,0,264,QPen(Qt::black));
    scene->setSceneRect(0,0,0,0);

    QGraphicsView * view = new QGraphicsView(this);

    view->setScene(scene);

    ui->board->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_make_clicked()
{
    if(recmode==1)
    {
        rectangle rerec;
        rerec.draw(scene,rerec.rectangle1);
    }
    if(cirmode==1)
    {
        circle recir;
        recir.draw(scene,recir.circle1);
    }
    if(trimode==1)
    {
        triangle retri;
        retri.draw(scene,retri.triangle1);
    }
}

void MainWindow::on_rectangle_clicked()
{
    recmode=1;
    cirmode=0;
    trimode=0;
}

void MainWindow::on_triangle_clicked()
{
    recmode=0;
    cirmode=0;
    trimode=1;
}

void MainWindow::on_circle_clicked()
{
    recmode=0;
    cirmode=1;
    trimode=0;
}


void MainWindow::on_returnx_returnPressed()
{
    rectangle rerec;
    triangle retri;
    rerec.recx=ui->returnx->text().toInt();
    retri.trix=ui->returnx->text().toInt();
    qDebug()<<"recx"<<rerec.recx;
    qDebug()<<"trix"<<retri.trix;
}


void MainWindow::on_returny_returnPressed()
{
    rectangle rerec;
    triangle retri;
    rerec.recy=ui->returnx->text().toInt();
    retri.triy=ui->returnx->text().toInt();
    qDebug()<<"recy"<<rerec.recy;
    qDebug()<<"triy"<<retri.triy;
}

QGraphicsItem *MainWindow::getSelectedItem()
{
    if(scene->selectedItems().count() > 0){
        return scene->selectedItems().at(0);
    }
    return  nullptr;
}

void MainWindow::on_dial_valueChanged(int value)
{
    if(recmode==1)
    {
        value=1.5;
        rectangle rerec;
        rerec.rotate(getSelectedItem(),value);
    }

    if(trimode==1)
    {
        value=1.5;
        triangle retri;
        retri.rotate(getSelectedItem(),value);
    }
    if(cirmode==1)
    {
        value=1.5;
        circle recir;
        recir.rotate(getSelectedItem(),value);

    }
}

void MainWindow::on_movex_valueChanged(int value)
{

    if(recmode==1)
    {
        rectangle rerec;
        rerec.move(getSelectedItem(),value,0);
    }

    if(trimode==1)
    {
        triangle retri;
        retri.move(getSelectedItem(),value,0);
    }
    if(cirmode==1)
    {
        circle recir;
        recir.move(getSelectedItem(),value,0);
    }

}

void MainWindow::on_spinBox_2_valueChanged(int value)
{

    if(recmode==1)
    {
        rectangle rerec;
        rerec.move(getSelectedItem(),0,value);
    }

    if(trimode==1)
    {
        triangle retri;
        retri.move(getSelectedItem(),0,value);
    }
    if(cirmode==1)
    {
        circle recir;
        recir.move(getSelectedItem(),0,value);

    }
}

