#include "QtConfig.h"

#include "config.h"

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());

	ui.commandInAddButton->setEnabled(false);
	ui.commandOutAddButton->setEnabled(false);

	for (int i = 0; i < config->blockIncoming.size(); i++)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem();
		item->setText(0, QString::fromStdString(config->blockIncoming[i]));
		ui.commandInList->addTopLevelItem(item);
	}
	
	for (int i = 0; i < config->blockOutgoing.size(); i++)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem();
		item->setText(0, QString::fromStdString(config->blockOutgoing[i]));
		ui.commandOutList->addTopLevelItem(item);
	}
}

QtConfig::~QtConfig()
{
}

void QtConfig::checkInAddButton()
{
	ui.commandInAddButton->setEnabled(!ui.commandInLine->text().isEmpty());
}

void QtConfig::checkOutAddButton()
{
	ui.commandOutAddButton->setEnabled(!ui.commandOutLine->text().isEmpty());
}

void QtConfig::commandInAdd()
{
	if (ui.commandInLine->text().isEmpty())
		return;

	QTreeWidgetItem* item = new QTreeWidgetItem();
	item->setText(0, ui.commandInLine->text());
	ui.commandInList->addTopLevelItem(item);
}

void QtConfig::commandOutAdd()
{
	if (ui.commandOutLine->text().isEmpty())
		return;

	QTreeWidgetItem* item = new QTreeWidgetItem();
	item->setText(0, ui.commandOutLine->text());
	ui.commandOutList->addTopLevelItem(item);
}

void QtConfig::commandInDelete()
{
	QTreeWidgetItem* item = ui.commandInList->currentItem();
	if (item == nullptr)
		return;

	ui.commandInList->takeTopLevelItem(ui.commandInList->currentIndex().row());
	ui.commandInLine->setText(item->text(0));
}

void QtConfig::commandOutDelete()
{
	QTreeWidgetItem* item = ui.commandOutList->currentItem();
	if (item == nullptr)
		return;

	ui.commandOutList->takeTopLevelItem(ui.commandOutList->currentIndex().row());
	ui.commandOutLine->setText(item->text(0));
}

void QtConfig::saveToConfig()
{
	config->blockIncoming.clear();
	config->blockOutgoing.clear();

	for (int i = 0; i < ui.commandInList->topLevelItemCount(); i++)
	{
		QString text = ui.commandInList->topLevelItem(i)->text(0);
		if (text.isEmpty())
			continue;
		config->blockIncoming.push_back(text.toStdString());
	}

	for (int i = 0; i < ui.commandOutList->topLevelItemCount(); i++)
	{
		QString text = ui.commandOutList->topLevelItem(i)->text(0);
		if (text.isEmpty())
			continue;
		config->blockOutgoing.push_back(text.toStdString());
	}

	config->writeConfig();
}