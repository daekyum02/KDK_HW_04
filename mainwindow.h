#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainwindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QDialog>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWidget>
#include <QTimer>
#include <fstream>
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    int recmode=0;
    int cirmode=0;
    int trimode=0;
    int rotation_angle;
    QGraphicsItem *getSelectedItem();
private slots:
    void on_triangle_clicked();
    void on_returnx_returnPressed();
    void on_returny_returnPressed();
    void on_rectangle_clicked();
    void on_circle_clicked();
    void on_make_clicked();
    void on_dial_valueChanged(int value);
    void on_movex_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
};

#endif // MAINWINDOW_H
