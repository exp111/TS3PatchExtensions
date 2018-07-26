#pragma once
#include "ui_QtManualBadges.h"

#include <string>
#include <vector>

class QtManualBadges : public QMainWindow
{
	Q_OBJECT

public:
	QtManualBadges(QWidget *parent = Q_NULLPTR);
	~QtManualBadges();

public slots:
	void saveToConfig();
	void addBadge();

private:
	std::vector<QLineEdit*> inputLines;
	Ui::BadgesWindow ui;
};