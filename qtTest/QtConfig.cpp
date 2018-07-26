#include "QtConfig.h"

#include "config.h"

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.checkBox->setChecked(config->testBool);
}

QtConfig::~QtConfig()
{
}

void QtConfig::saveToConfig()
{
	config->testBool = ui.checkBox->isChecked();
}