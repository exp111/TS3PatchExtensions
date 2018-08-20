#include "QtConfig.h"

#include "config.h"

int getIndex(vector<pair<string, string>> vec, string value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		pair<string, string> pair = vec[i];
		if (pair.first == value || pair.second == value)
			return i;
	}
	return 0;
}

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~ Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());

	updateCombos();

	if (!config->foundCSV)
	{
		QMessageBox* notifyUserDialog = new QMessageBox(QMessageBox::Icon::Warning, "Missing CSV File", ("Missing File: " + config->directory + config->csvName + ". Download it from <a href='" + config->csvUrl + "'>here</a> or press the update button.").c_str(), QMessageBox::NoButton, parent);
		notifyUserDialog->setWindowIcon(QIcon());
		notifyUserDialog->setAttribute(Qt::WA_DeleteOnClose);
		notifyUserDialog->show();
	}
}

QtConfig::~QtConfig()
{
}

void QtConfig::updateCombos()
{
	for (auto os : config->OSList)
		ui.OSComboBox->addItem(QString(os.c_str()));

	//No need to add versions to other combo as the updateVersionCombo action gets triggered by the currentIndexChanged event here

	ui.OSComboBox->setCurrentIndex(std::find(config->OSList.begin(), config->OSList.end(), config->OS) - config->OSList.begin());
	ui.versionComboBox->setCurrentIndex(getIndex(config->versionList[config->OS], config->version));
}

void QtConfig::updateVersionCombo(QString newOS)
{
	vector<pair<string, string>> versions = config->versionList[newOS.toStdString().c_str()];

	ui.versionComboBox->clear();
	for (auto versionPair : versions)
		ui.versionComboBox->addItem(QString(versionPair.first.c_str()));
}

void QtConfig::saveToConfig()
{
	string OS = config->OSList[ui.OSComboBox->currentIndex()];
	config->OS = OS;
	pair<string, string> versionPair = config->versionList[OS][ui.versionComboBox->currentIndex()];
	config->version = versionPair.first;
	config->versionHash = versionPair.second;

	config->writeConfig();
}

void QtConfig::updateCSV()
{
	config->getCSV();
	config->readCSV();
	updateCombos();
}