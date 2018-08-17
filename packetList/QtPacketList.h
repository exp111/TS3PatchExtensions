#pragma once

#include "GeneratedFiles/ui_QtPacketList.h"

#include <QWidget>
#include <QMainWindow>
#include <QClipboard>

#include "config.h"

class QtPacketList : public QMainWindow
{
	Q_OBJECT

public:
	QtPacketList(QWidget* parent = Q_NULLPTR);
	~QtPacketList();

public slots:
	void updateLists();
	void copyTextToClipboard(QTreeWidgetItem*);

private:
	Ui::QtPacketList ui;
};
