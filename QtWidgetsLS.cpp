#include <QFileDialog>
#include <QMessageBox>
#include <qcompleter.h>
#include <qlistview.h>
#include "QtWidgetsLS.h"
#include "logiclayer.h"
#include "MAP.h"
QtWidgetsLS::QtWidgetsLS(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonSearch, SIGNAL(clicked()), this, SLOT(inputloc()), Qt::UniqueConnection);
	connect(ui.pushButtonExit, SIGNAL(clicked()), this, SLOT(close()), Qt::UniqueConnection);
	connect(ui.comboBoxStart, SIGNAL(currentIndexChanged(Qstring)), this, SLOT(startsearch()), Qt::UniqueConnection);
	connect(ui.comboBoxEnd, SIGNAL(currentIndexChanged(Qstring)), this, SLOT(endsearch()), Qt::UniqueConnection);
}

QtWidgetsLS::~QtWidgetsLS()
{
}

void QtWidgetsLS::myShow(QGraphicsView* p) {
	parnt = p;
	show();
}
void QtWidgetsLS::inputloc() {

}
void QtWidgetsLS::startsearch() {

}
void QtWidgetsLS::endsearch() {

}
