#include "QtConfig.h"

#include "config.h"

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.blockSetConnectionInfoBox->setChecked(config->blockSetConnectionInfo);
	ui.blockConnectionInfoAutoUpdateBox->setChecked(config->blockConnectionInfoAutoUpdate);

	size_t setConnectionInfoSize = config->setConnectionInfo.size();
	for (int i = 0; i < setConnectionInfoSize; i++)
	{
		ui.tableWidget->insertRow(i);
		QTableWidgetItem* item = new QTableWidgetItem(QString(get<0>(config->setConnectionInfo[i]).c_str()));
		ui.tableWidget->setItem(i, 0, item);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString(get<1>(config->setConnectionInfo[i]).c_str()));
		ui.tableWidget->setItem(i, 1, item2);
		QTableWidgetItem* item3 = new QTableWidgetItem();
		item3->setCheckState(get<2>(config->setConnectionInfo[i]) ? Qt::Checked : Qt::Unchecked);
		ui.tableWidget->setItem(i, 2, item3);
	}

	size_t connectionInfoAutoUpdateSize = config->connectionInfoAutoUpdate.size();
	for (int i = 0; i < connectionInfoAutoUpdateSize; i++)
	{
		int j = setConnectionInfoSize + i;
		ui.tableWidget->insertRow(j);
		QTableWidgetItem* item = new QTableWidgetItem(QString(get<0>(config->connectionInfoAutoUpdate[i]).c_str()));
		ui.tableWidget->setItem(j, 0, item);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString(get<1>(config->connectionInfoAutoUpdate[i]).c_str()));
		ui.tableWidget->setItem(j, 1, item2);
		QTableWidgetItem* item3 = new QTableWidgetItem();
		item3->setCheckState(get<2>(config->connectionInfoAutoUpdate[i]) ? Qt::Checked : Qt::Unchecked);
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
		get<1>(config->setConnectionInfo[i]) = ui.tableWidget->item(i, 1)->text().toStdString();
		get<2>(config->setConnectionInfo[i]) = ui.tableWidget->item(i, 2)->checkState() == Qt::Checked ? true : false;
	}

	size_t connectionInfoAutoUpdateSize = config->connectionInfoAutoUpdate.size();
	for (int i = 0; i < connectionInfoAutoUpdateSize; i++)
	{
		int j = setConnectionInfoSize + i;
		get<1>(config->connectionInfoAutoUpdate[i]) = ui.tableWidget->item(j, 1)->text().toStdString();
		get<2>(config->connectionInfoAutoUpdate[i]) = ui.tableWidget->item(j, 2)->checkState() == Qt::Checked ? true : false;
	}

	config->writeConfig();
}