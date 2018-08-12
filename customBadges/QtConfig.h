#pragma once
#include "GeneratedFiles\ui_QtConfig.h"

#include <QMessageBox>
#include <string>
#include <vector>

#include "QtManualBadges.h"

class QtConfig : public QMainWindow
{
	Q_OBJECT
	friend QtManualBadges;
public:
	QtConfig(QWidget *parent = Q_NULLPTR);
	~QtConfig();

public slots:
	void updateBoxes();
	void saveToConfig();
	void addBadge(QTreeWidgetItem* item);
	void deleteBadge1();
	void deleteBadge2();
	void deleteBadge3();

	void openManualBadges();

private:
	Ui::QtConfig ui;
	std::vector<std::string> tempBadges;
	std::vector<int> tempBadgeIDs;
};