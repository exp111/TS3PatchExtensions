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
	void updateBoxes();
	void updateBadgeList();

public slots:
	void saveToConfig();
	void addBadge(QTreeWidgetItem*);
	void deleteBadge1();
	void deleteBadge2();
	void deleteBadge3();
	void swapBadge(QString label, QTreeWidgetItem*);
	void updateIcons();

	void openManualBadges();

private:
	Ui::QtConfig ui;
	std::vector<std::string> tempBadges;
	std::vector<int> tempBadgeIDs;
};