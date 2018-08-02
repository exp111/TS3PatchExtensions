#pragma once

#include <qwidget.h>
#include <qmainwindow.h>
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
public slots:
	void saveToConfig();
	void updateVersionCombo(QString newCombo);
private:
	Ui::QtConfig ui;
};
