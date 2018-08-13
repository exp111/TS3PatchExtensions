#include "QtConfig.h"

#include "config.h"
#include "customBadges.h"

QtConfig::QtConfig(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags &~Qt::WindowMinMaxButtonsHint);
	this->setMinimumSize(this->size());
	this->setMaximumSize(this->size());

	//Badge Stuff
	ui.overwolfCheckBox->setChecked(config->overwolfBadge);
	tempBadges = config->badges;
	tempBadgeIDs = config->badgeIDs;
	updateBoxes();
	QIcon windowIcon;
	windowIcon.addFile(QString(config->getIconPath("addon_author", false).c_str()));
	this->setWindowIcon(windowIcon);

	if (config->foundCSV)
	{
		for (int i = 0; i < config->badgeCount; i++)
		{
			QTreeWidgetItem* item = new QTreeWidgetItem();
			item->setText(0, QString(get<1>(config->allBadges[i]).c_str()));
			string fileName = config->getIconPath(get<3>(config->allBadges[i]), false);
			QIcon icon;
			icon.addFile(QString(fileName.c_str()));
			item->setIcon(0, icon);
			string fileName64 = config->getIconPath(get<3>(config->allBadges[i]), true);
			string tooltip = "<center><b>" + get<1>(config->allBadges[i]) + "</b><br/>" + get<2>(config->allBadges[i]) + "<br/><img width=\"64\" height=\"64\" src=\"" + fileName64 + "\"</center>";
			item->setToolTip(0, QString(tooltip.c_str()));
			ui.badgeList->insertTopLevelItem(i, item);
		}
	}
	else
	{
		QMessageBox* notifyUserDialog = new QMessageBox(QMessageBox::Icon::Warning, "Missing CSV File", ("Missing File: " + config->directory + config->csvName + ". Download it from <a href='" + config->csvUrl + "'>here</a>.").c_str(), QMessageBox::NoButton, parent);
		notifyUserDialog->setWindowIcon(QIcon());
		notifyUserDialog->setAttribute(Qt::WA_DeleteOnClose);
		notifyUserDialog->show();
	}
}

QtConfig::~QtConfig()
{
}

void QtConfig::updateBoxes()
{
	for (int i = 0; i < tempBadges.size(); i++)
	{
		if (config->badgeCount < tempBadgeIDs[i])
			continue;

		string filePath = config->getIconPath(get<3>(config->allBadges[tempBadgeIDs[i]]), true);
		QString fileName(filePath.c_str());
		QImage image(fileName);
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

void QtConfig::addBadge(QTreeWidgetItem*)
{
	if (tempBadges.size() > MAX_BADGES)
		return;

	int index = ui.badgeList->currentIndex().row();
	tempBadges.push_back(get<0>(config->allBadges[index]));
	tempBadgeIDs.push_back(index);

	updateBoxes();
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

	updateBoxes();
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

	updateBoxes();
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

	updateBoxes();
}

void QtConfig::swapBadge(QString label, QTreeWidgetItem*)
{
	int i = -1;
	if (label.compare("badge1Label", Qt::CaseInsensitive) == 0)
	{
		i = 0;
	}
	else if (label.compare("badge2Label", Qt::CaseInsensitive) == 0)
	{
		i = 1;
	}
	else if (label.compare("badge3Label", Qt::CaseInsensitive) == 0)
	{
		i = 2;
	}

	if (i == -1)
		return;

	if (tempBadges.size() < i)
		return;

	int index = ui.badgeList->currentIndex().row();
	tempBadges[i] = get<0>(config->allBadges[index]);
	tempBadgeIDs[i] = index;

	updateBoxes();
}

void QtConfig::openManualBadges()
{
	QtManualBadges* window = new QtManualBadges((QWidget*)this);
	window->setAttribute(Qt::WA_DeleteOnClose);
	window->show();
}
