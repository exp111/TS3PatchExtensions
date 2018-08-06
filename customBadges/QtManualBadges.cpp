#include "QtManualBadges.h"

#include "QtConfig.h"

#include "config.h"

#include <qlineedit.h>

QtManualBadges::QtManualBadges(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	size_t toMove = (((QtConfig*)parent)->tempBadges.size() - 2);
	if (toMove > 0)
	{
		this->resize(size().width(), size().height() + 20 * toMove);
		ui.closeButton->move(ui.closeButton->pos().x(), ui.closeButton->pos().y() + 20 * toMove);
		ui.addButton->move(ui.addButton->pos().x(), ui.addButton->pos().y() + 20 * toMove);
	}
	//unsafe but as we always call this as the child of the config it's okay
	for (int i = 0; i < ((QtConfig*)parent)->tempBadges.size(); i++)
	{
		QLineEdit* neu = new QLineEdit(this);
		neu->resize(211, 20);
		neu->move(20, 20 + 30 * i);
		neu->setText(QString(((QtConfig*)parent)->tempBadges[i].c_str()));
		inputLines.push_back(neu);
	}
}

QtManualBadges::~QtManualBadges()
{
}

int findID(std::string string)
{
	for (unsigned i = 0; i < config->badgesGUID->size(); i++)
	{
		if (config->badgesGUID[i] == string)
			return i;
		else 
			continue;
	}
	return -1;
}

void QtManualBadges::saveToConfig()
{
	for (int i = 0; i < inputLines.size(); i++)
	{
		if (inputLines[i]->text().isEmpty())
			continue;

		if (i >= ((QtConfig*)this->parentWidget())->tempBadges.size())
		{
			((QtConfig*)this->parentWidget())->tempBadges.push_back("1cb07348-34a4-4741-b50f-c41e584370f7");
			((QtConfig*)this->parentWidget())->tempBadgeIDs.push_back(0);
		}
		((QtConfig*)this->parentWidget())->tempBadges[i] = inputLines[i]->text().toStdString();
		((QtConfig*)this->parentWidget())->tempBadgeIDs[i] = findID(inputLines[i]->text().toStdString());
	}

	((QtConfig*)this->parentWidget())->updateBoxes();
}

void QtManualBadges::addBadge()
{
	if (inputLines.size() >= 3) //if we add a new one over the badge limit resize the window
	{
		int toMove = (inputLines.size() - 2);
		this->resize(size().width(), size().height() + 30);
		ui.closeButton->move(ui.closeButton->pos().x(), ui.closeButton->pos().y() + 30);
		ui.addButton->move(ui.addButton->pos().x(), ui.addButton->pos().y() + 30);
	}
	QLineEdit* neu = new QLineEdit(this);
	neu->resize(211, 20);
	neu->move(20, 20 + 30 * inputLines.size());
	neu->show();
	inputLines.push_back(neu);
}