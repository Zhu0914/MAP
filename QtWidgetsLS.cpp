#include <QFileDialog>
#include <QMessageBox>
#include <qcompleter.h>
#include <qlistview.h>
#include <QtTest/QtTest>
#include "QtWidgetsLS.h"
#include "logiclayer.h"
#include "MAP.h"
#include <iostream>
#include "ui_MAP.h"
//#include "main.cpp"
QtWidgetsLS::QtWidgetsLS(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonSearch, SIGNAL(clicked()), this, SLOT(inputloc()), Qt::UniqueConnection);
	connect(ui.pushButtonExit, SIGNAL(clicked()), this, SLOT(close()), Qt::UniqueConnection);
	connect(ui.comboBoxStart, SIGNAL(currentIndexChanged(QString)), this, SLOT(startsearch(QString)), Qt::UniqueConnection);
	connect(ui.comboBoxEnd, SIGNAL(currentIndexChanged(QString)), this, SLOT(endsearch(QString)), Qt::UniqueConnection);
}

QtWidgetsLS::~QtWidgetsLS()
{
}

void QtWidgetsLS::myShow(QGraphicsView* p) {
	parnt = p;
	show();
}
void QtWidgetsLS::readloc() {
	string a;
	char d;
	int b, c;
	location tmp;
	fstream fstrm;
	fstrm.open("organization.txt");
	if (!fstrm.is_open())
		cout << "Open file failure" << endl;
	while (!fstrm.eof()) {
		fstrm >> a >> b >> d >>c;
		tmp.la = a;
		tmp.lx = b;
		tmp.ly = c;
		loc.push_back(tmp);
		list << QString::fromStdString(a);
	}
	fstrm.close();
	ui.comboBoxStart->addItems(list);
	ui.comboBoxEnd->addItems(list);

}
void QtWidgetsLS::inputloc() {
	string begin= ui.comboBoxStart->currentText().toStdString();
	string end= ui.comboBoxEnd->currentText().toStdString();
	//QWidget* child =;
	for (auto i : loc) {
		if (begin == i.la) {
			((MyScene*)(parnt->scene()))->clickmouse(i.lx, i.ly, 1);
			break;
			//QTest::mouseClick(child, Qt::LeftButton, Qt::NoModifier, QPoint(i.lx, i.ly));
			//SetCursorPos(i.lx, i.ly);//设置鼠标位置
			////中间的0能够不要管
			//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, GetMessageExtraInfo());//down
			//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, GetMessageExtraInfo());//up
		}
	}
	for (auto i : loc) {
		if (end == i.la) {
			((MyScene*)(parnt->scene()))->clickmouse(i.lx, i.ly, 2);
			break;
			//QTest::mouseClick(child, Qt::RightButton, Qt::NoModifier, QPoint(i.lx, i.ly));
		}
	}
	close();
}
void QtWidgetsLS::startsearch(QString) {
	ui.comboBoxStart->setEditable(true);
	QCompleter* pCompleter = new QCompleter(list, this);
	pCompleter->setCaseSensitivity(Qt::CaseInsensitive);
	ui.comboBoxStart->setCompleter(pCompleter);
}
void QtWidgetsLS::endsearch(QString) {
	ui.comboBoxEnd->setEditable(true);
	QCompleter* pCompleter = new QCompleter(list, this);
	ui.comboBoxEnd->setCompleter(pCompleter);
}
