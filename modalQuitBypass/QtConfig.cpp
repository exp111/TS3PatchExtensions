#include "QtConfig.h"

#include "config.h"

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~ Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());

	ui.hostMessageLine->setText(QString::fromStdString(config->hostMessage));
	ui.hostModeSpin->setValue(config->hostMode);
}

QtConfig::~QtConfig()
{
}

void QtConfig::saveToConfig()
{
	config->hostMessage = ui.hostMessageLine->text().toStdString();
	config->hostMode = ui.hostModeSpin->value();
}