#include "QtPacketList.h"

QtPacketList::QtPacketList(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());

	updateLists();
}

QtPacketList::~QtPacketList()
{
}

void QtPacketList::copyTextToClipboard(QTreeWidgetItem* item)
{
	QClipboard* clipboard = QApplication::clipboard();
	clipboard->setText(item->text(0));
}

void QtPacketList::updateLists()
{
	ui.packetInList->clear();
	for (int i = 0; i < config->packetsIn.size(); i++)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem;
		item->setText(0, config->packetsIn[i]);
		item->setToolTip(0, config->packetsIn[i]);
		ui.packetInList->insertTopLevelItem(i, item);
	}

	ui.packetOutList->clear();
	for (int i = 0; i < config->packetsOut.size(); i++)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem;
		item->setText(0, config->packetsOut[i]);
		item->setToolTip(0, config->packetsOut[i]);
		ui.packetOutList->insertTopLevelItem(i, item);
	}
}
