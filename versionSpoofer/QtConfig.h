#pragma once

#include <qwidget.h>
#include <qmainwindow.h>
#include <QMessageBox>
#include "GeneratedFiles\ui_QtConfig.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class QtConfig : public QMainWindow
{
	Q_OBJECT

public:
	QtConfig(QWidget *parent = Q_NULLPTR);
	~QtConfig();
	void updateCombos();
public slots:
	void saveToConfig();
	void updateVersionCombo(QString newCombo);
	void updateCSV();
private:
	Ui::QtConfig ui;
};
