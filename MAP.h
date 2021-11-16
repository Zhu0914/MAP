#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsRectItem>
#include "ui_MAP.h"
class QtWidgetsFL;
class QtWidgetsLS;
class MAP : public QMainWindow
{
    Q_OBJECT

public:
    MAP(QWidget *parent = Q_NULLPTR);
    ~MAP();
private:
    Ui::MAPClass ui;
    QtWidgetsLS *ls;
    QtWidgetsFL *fl;
    QTimer* m_Timer;
    QGraphicsItemGroup* gItem;
    void deleteItems();
protected:
    void closeEvent(QCloseEvent* event);
private  slots:
    void loadmap();
    void closewnd();
    void zszc();
    void zdjl();
    void zdcx();
};
/////////////////////////////////////////////////////////////
class MyScene : public QGraphicsScene
{

public:
    explicit MyScene(QObject* parent = 0);
    void stopLines(QGraphicsView*);
protected:
    QGraphicsView* qgv;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);//����mousePressEvent�Բ�������¼�
    void mousePressEvent(QGraphicsSceneMouseEvent* event);//����mousePressEvent�Բ�������¼�
signals:
public slots:
};
//////////////////////////////////////////////////////////////
class MyItem : public QGraphicsRectItem {
    int cx, cy;  //���ʱ������
    int cf;      //������=1����ʾ�ص㣬�Ҽ����=2��ʾ�յ�
    int cs;      //�����õ���������
    int bs[6];   //�����6��վ���վ����
public:
    MyItem(int x, int y, int f);
    MyItem& operator<<(int s);
    int operator()(int x, int y);
    int& x();
    int& y();
    int& f();
    int& c();
    int& operator[](int);
    int checkAllStops();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};
