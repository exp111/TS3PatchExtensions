#include "QtConfig.h"

#include "config.h"
#include "customBadges.h"

QtConfig::QtConfig(QWidget *parent, int currentTab)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Badge Stuff
	ui.overwolfCheckBox->setChecked(config->overwolfBadge);
	tempBadges = config->badges;
	tempBadgeIDs = config->badgeIDs;
	updateBoxes();
}

QtConfig::~QtConfig()
{
}

void QtConfig::updateBoxes()
{
	for (int i = 0; i < tempBadges.size(); i++)
	{
		std::string s = config->directory + "icons/" + config->badgesIcons[tempBadgeIDs[i]] + ".png";
		QString filename(s.c_str());
		QImage image(filename);
		switch (i)
		{
		case 0:
			ui.badge1Label->setPixmap(QPixmap::fromImage(image));
			break;
		case 1:
			ui.badge2Label->setPixmap(QPixmap::fromImage(image));
			break;
		case 2:
			ui.badge3Label->setPixmap(QPixmap::fromImage(image));
			break;
		default:
			break;
		}
	}

	for (size_t i = tempBadges.size(); i < MAX_BADGES; i++) //delete empty ones
	{
		QPixmap null = QPixmap();
		switch (i)
		{
		case 0:
			ui.badge1Label->setPixmap(null);
			break;
		case 1:
			ui.badge2Label->setPixmap(null);
			break;
		case 2:
			ui.badge3Label->setPixmap(null);
			break;
		default:
			break;
		}
	}
}

void QtConfig::saveToConfig()
{
	//Badge Stuff
	config->overwolfBadge = ui.overwolfCheckBox->isChecked();
	config->badges = tempBadges;
	config->badgeIDs = tempBadgeIDs;
	sendBadgeCommand();
	config->writeConfig();
}

void QtConfig::addBadge(QTreeWidgetItem* item)
{
	if (tempBadges.size() > MAX_BADGES)
		return;
	
	int index = ui.badgeList->currentIndex().row();
	tempBadges.push_back(config->badgesGUID[index]);
	tempBadgeIDs.push_back(index);
}

void QtConfig::deleteBadge1()
{
	if (tempBadges.size() > 0)
	{
		for (int i = 1; i < tempBadges.size(); i++)
		{
			tempBadges[i - 1] = tempBadges[i];
			tempBadgeIDs[i - 1] = tempBadgeIDs[i];
		}
		tempBadges.pop_back();
		tempBadgeIDs.pop_back();
	}
}

void QtConfig::deleteBadge2()
{
	if (tempBadges.size() > 1)
	{
		for (int i = 2; i < tempBadges.size(); i++)
		{
			tempBadges[i - 1] = tempBadges[i];
			tempBadgeIDs[i - 1] = tempBadgeIDs[i];
		}
		tempBadges.pop_back();
		tempBadgeIDs.pop_back();
	}
}

void QtConfig::deleteBadge3()
{
	if (tempBadges.size() > 2)
	{
		for (int i = 3; i < tempBadges.size(); i++)
		{
			tempBadges[i - 1] = tempBadges[i];
			tempBadgeIDs[i - 1] = tempBadgeIDs[i];
		}
		tempBadges.pop_back();
		tempBadgeIDs.pop_back();
	}
}

void QtConfig::openManualBadges()
{
	QtManualBadges* window = new QtManualBadges((QWidget*)this);
	window->setAttribute(Qt::WA_DeleteOnClose);
	window->show();
}
