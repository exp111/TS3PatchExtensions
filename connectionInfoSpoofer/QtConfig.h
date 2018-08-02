#pragma once

#include <qwidget.h>
#include <qmainwindow.h>
#include <qlineedit.h>
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
private:
	Ui::QtConfig ui;
	std::vector<QLineEdit*> inputLines;
};
