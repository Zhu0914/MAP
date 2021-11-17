#pragma once
#include <map>
#include <utility>
#include <fstream>
using namespace std;
#include <QWidget>
#include <qmainwindow.h>
#include "ui_QtWidgetsLS.h"
#include <QString>
struct location {
	string la;
	int lx;
	int ly;
};
class QtWidgetsLS : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsLS(QWidget *parent = Q_NULLPTR);
	~QtWidgetsLS();
	QGraphicsView* parnt;
	void myShow(QGraphicsView* p);
	void readloc(); 
private:
	Ui::QtWidgetsLS ui;
	vector<location> loc;
	QStringList list;
private slots:
	void inputloc();
	void startsearch(QString);
	void endsearch(QString);
};
