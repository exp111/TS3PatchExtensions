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

	ui.blockSetConnectionInfoBox->setChecked(config->blockSetConnectionInfo);
	ui.blockConnectionInfoAutoUpdateBox->setChecked(config->blockConnectionInfoAutoUpdate);

	size_t setConnectionInfoSize = config->setConnectionInfo.size();
	for (int i = 0; i < setConnectionInfoSize; i++)
	{
		ui.tableWidget->insertRow(i);
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(config->setConnectionInfo[i].name));
		ui.tableWidget->setItem(i, 0, item);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(config->setConnectionInfo[i].value));
		ui.tableWidget->setItem(i, 1, item2);
		QTableWidgetItem* item3 = new QTableWidgetItem();
		item3->setCheckState(config->setConnectionInfo[i].useOriginal ? Qt::Checked : Qt::Unchecked);
		ui.tableWidget->setItem(i, 2, item3);
	}

	size_t connectionInfoAutoUpdateSize = config->connectionInfoAutoUpdate.size();
	for (int i = 0; i < connectionInfoAutoUpdateSize; i++)
	{
		int j = (int)setConnectionInfoSize + i;
		ui.tableWidget->insertRow(j);
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(config->connectionInfoAutoUpdate[i].name));
		ui.tableWidget->setItem(j, 0, item);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(config->connectionInfoAutoUpdate[i].value));
		ui.tableWidget->setItem(j, 1, item2);
		QTableWidgetItem* item3 = new QTableWidgetItem();
		item3->setCheckState(config->connectionInfoAutoUpdate[i].useOriginal ? Qt::Checked : Qt::Unchecked);
		ui.tableWidget->setItem(j, 2, item3);
	}

	ui.tableWidget->setColumnWidth(0, 280);
	ui.tableWidget->setColumnWidth(1, 45);
	ui.tableWidget->setColumnWidth(2, 45);
}

QtConfig::~QtConfig()
{
}

void QtConfig::saveToConfig()
{
	config->blockSetConnectionInfo = ui.blockSetConnectionInfoBox->isChecked();
	config->blockConnectionInfoAutoUpdate = ui.blockConnectionInfoAutoUpdateBox->isChecked();

	size_t setConnectionInfoSize = config->setConnectionInfo.size();
	for (int i = 0; i < setConnectionInfoSize; i++)
	{
		config->setConnectionInfo[i].value = ui.tableWidget->item(i, 1)->text().toStdString();
		config->setConnectionInfo[i].useOriginal = ui.tableWidget->item(i, 2)->checkState() == Qt::Checked ? true : false;
	}

	size_t connectionInfoAutoUpdateSize = config->connectionInfoAutoUpdate.size();
	for (int i = 0; i < connectionInfoAutoUpdateSize; i++)
	{
		int j = (int)setConnectionInfoSize + i;
		config->connectionInfoAutoUpdate[i].value = ui.tableWidget->item(j, 1)->text().toStdString();
		config->connectionInfoAutoUpdate[i].useOriginal = ui.tableWidget->item(j, 2)->checkState() == Qt::Checked ? true : false;
	}

	config->writeConfig();
}