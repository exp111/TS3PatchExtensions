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
		QTableWidgetItem* item = new QTableWidgetItem(QString(config->setConnectionInfo[i].first.c_str()));
		ui.tableWidget->setItem(i, 0, item);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString(config->setConnectionInfo[i].second.c_str()));
		ui.tableWidget->setItem(i, 1, item2);
	}

	size_t connectionInfoAutoUpdateSize = config->connectionInfoAutoUpdate.size();
	for (int i = 0; i < connectionInfoAutoUpdateSize; i++)
	{
		int j = setConnectionInfoSize + i;
		ui.tableWidget->insertRow(j);
		QTableWidgetItem* item = new QTableWidgetItem(QString(config->connectionInfoAutoUpdate[i].first.c_str()));
		ui.tableWidget->setItem(j, 0, item);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString(config->connectionInfoAutoUpdate[i].second.c_str()));
		ui.tableWidget->setItem(j, 1, item2);
	}
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
		config->setConnectionInfo[i].second = ui.tableWidget->item(i, 1)->text().toStdString();
	}

	size_t connectionInfoAutoUpdateSize = config->connectionInfoAutoUpdate.size();
	for (int i = 0; i < connectionInfoAutoUpdateSize; i++)
	{
		int j = setConnectionInfoSize + i;
		config->connectionInfoAutoUpdate[i].second = ui.tableWidget->item(j, 1)->text().toStdString();
	}

	config->writeConfig();
}