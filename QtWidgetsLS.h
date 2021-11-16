#pragma once

#include <QWidget>
#include <qmainwindow.h>
#include "ui_QtWidgetsLS.h"

class QtWidgetsLS : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsLS(QWidget *parent = Q_NULLPTR);
	~QtWidgetsLS();
	QGraphicsView* parnt;
	void myShow(QGraphicsView* p);
private:
	Ui::QtWidgetsLS ui;
private slots:
	void inputloc();
	void startsearch();
	void endsearch();
};
