#include "QtConfig.h"

#include "config.h"

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.checkBox->setChecked(config->testBool);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());
}

QtConfig::~QtConfig()
{
}

void QtConfig::saveToConfig()
{
	config->testBool = ui.checkBox->isChecked();
}