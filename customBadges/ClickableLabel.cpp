#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
	: QLabel(parent) 
{
	setAcceptDrops(true);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::dragEnterEvent(QDragEnterEvent* event)
{
	event->acceptProposedAction();
}

void ClickableLabel::dragMoveEvent(QDragMoveEvent* event)
{
	event->acceptProposedAction();
}

void ClickableLabel::dragLeaveEvent(QDragLeaveEvent* event)
{
	event->accept();
}

void ClickableLabel::dropEvent(QDropEvent* event)
{
	QObject* source = event->source();
	if (source->objectName().compare("badgeList", Qt::CaseInsensitive) != 0)
		return;

	if (this->pixmap()->isNull()) //is this an empty label?
		emit dropFromTreeWidgetOnEmpty(((QTreeWidget*)source)->currentItem());
	else
		emit dropFromTreeWidgetOnNotEmpty(this->objectName(), ((QTreeWidget*)source)->currentItem());

	event->acceptProposedAction();
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
	emit clicked();
}