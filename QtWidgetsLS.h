#pragma once

#include <QWidget>
#include "ui_QtWidgetsLS.h"

class QtWidgetsLS : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsLS(QWidget *parent = Q_NULLPTR);
	~QtWidgetsLS();

private:
	Ui::QtWidgetsLS ui;
};
