#pragma once

#include <QLabel>
#include <QDropEvent>
#include <QTreeWidget>

class ClickableLabel : public QLabel
{
	Q_OBJECT

public:
	explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ClickableLabel();

signals:
	void dropFromTreeWidgetOnEmpty(QTreeWidgetItem*);
	void dropFromTreeWidgetOnNotEmpty(QString, QTreeWidgetItem*);
	void clicked();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);
	void dropEvent(QDropEvent *event);
	void mousePressEvent(QMouseEvent* event);
};