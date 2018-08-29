#pragma once

#include <qwidget.h>
#include <qmainwindow.h>
#include "GeneratedFiles\ui_QtConfig.h"

class QtConfig : public QMainWindow
{
	Q_OBJECT

public:
	QtConfig(QWidget *parent = Q_NULLPTR);
	~QtConfig();
public slots:
	void saveToConfig();
	void checkInAddButton();
	void checkOutAddButton();
	void commandInAdd();
	void commandOutAdd();
	void commandInDelete();
	void commandOutDelete();
private:
	Ui::QtConfig ui;
};
