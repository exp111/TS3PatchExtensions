/********************************************************************************
** Form generated from reading UI file 'QtConfigp12692.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTCONFIGP12692_H
#define QTCONFIGP12692_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"

QT_BEGIN_NAMESPACE

class Ui_QtConfig
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QCheckBox *overwolfCheckBox;
    QTreeWidget *badgeList;
    QGroupBox *badge1Box;
    ClickableLabel *badge1Label;
    QGroupBox *badge3Box;
    ClickableLabel *badge3Label;
    QGroupBox *badge2Box;
    ClickableLabel *badge2Label;
    QToolButton *manualBadgeOverride;
    QPushButton *updateCSVButton;
    QPushButton *acceptButton;
    QPushButton *rejectButton;

    void setupUi(QMainWindow *QtConfig)
    {
        if (QtConfig->objectName().isEmpty())
            QtConfig->setObjectName(QStringLiteral("QtConfig"));
        QtConfig->resize(554, 429);
        centralWidget = new QWidget(QtConfig);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 531, 381));
        overwolfCheckBox = new QCheckBox(widget);
        overwolfCheckBox->setObjectName(QStringLiteral("overwolfCheckBox"));
        overwolfCheckBox->setGeometry(QRect(400, 50, 91, 17));
        QIcon icon;
        icon.addFile(QStringLiteral(":/badge/icons/overwolf.png"), QSize(), QIcon::Normal, QIcon::Off);
        overwolfCheckBox->setIcon(icon);
        badgeList = new QTreeWidget(widget);
        badgeList->setObjectName(QStringLiteral("badgeList"));
        badgeList->setGeometry(QRect(50, 120, 431, 241));
        badgeList->setDragDropOverwriteMode(false);
        badgeList->setDragDropMode(QAbstractItemView::DragOnly);
        badgeList->setDefaultDropAction(Qt::IgnoreAction);
        badgeList->setIndentation(0);
        badge1Box = new QGroupBox(widget);
        badge1Box->setObjectName(QStringLiteral("badge1Box"));
        badge1Box->setGeometry(QRect(60, 20, 101, 80));
        badge1Label = new ClickableLabel(badge1Box);
        badge1Label->setObjectName(QStringLiteral("badge1Label"));
        badge1Label->setGeometry(QRect(20, 12, 64, 64));
        badge1Label->setScaledContents(false);
        badge3Box = new QGroupBox(widget);
        badge3Box->setObjectName(QStringLiteral("badge3Box"));
        badge3Box->setGeometry(QRect(280, 20, 101, 80));
        badge3Label = new ClickableLabel(badge3Box);
        badge3Label->setObjectName(QStringLiteral("badge3Label"));
        badge3Label->setGeometry(QRect(20, 12, 64, 64));
        badge2Box = new QGroupBox(widget);
        badge2Box->setObjectName(QStringLiteral("badge2Box"));
        badge2Box->setGeometry(QRect(170, 20, 101, 80));
        badge2Label = new ClickableLabel(badge2Box);
        badge2Label->setObjectName(QStringLiteral("badge2Label"));
        badge2Label->setGeometry(QRect(20, 12, 64, 64));
        manualBadgeOverride = new QToolButton(widget);
        manualBadgeOverride->setObjectName(QStringLiteral("manualBadgeOverride"));
        manualBadgeOverride->setGeometry(QRect(420, 80, 61, 21));
        updateCSVButton = new QPushButton(widget);
        updateCSVButton->setObjectName(QStringLiteral("updateCSVButton"));
        updateCSVButton->setGeometry(QRect(430, 0, 101, 23));
        acceptButton = new QPushButton(centralWidget);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(90, 390, 131, 23));
        rejectButton = new QPushButton(centralWidget);
        rejectButton->setObjectName(QStringLiteral("rejectButton"));
        rejectButton->setGeometry(QRect(330, 390, 131, 23));
        QtConfig->setCentralWidget(centralWidget);

        retranslateUi(QtConfig);
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(rejectButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(badge1Label, SIGNAL(clicked()), QtConfig, SLOT(deleteBadge1()));
        QObject::connect(badge2Label, SIGNAL(clicked()), QtConfig, SLOT(deleteBadge2()));
        QObject::connect(badge3Label, SIGNAL(clicked()), QtConfig, SLOT(deleteBadge3()));
        QObject::connect(manualBadgeOverride, SIGNAL(clicked()), QtConfig, SLOT(openManualBadges()));
        QObject::connect(badgeList, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), QtConfig, SLOT(addBadge(QTreeWidgetItem*)));
        QObject::connect(badge1Label, SIGNAL(dropFromTreeWidgetOnEmpty(QTreeWidgetItem*)), QtConfig, SLOT(addBadge(QTreeWidgetItem*)));
        QObject::connect(badge2Label, SIGNAL(dropFromTreeWidgetOnEmpty(QTreeWidgetItem*)), QtConfig, SLOT(addBadge(QTreeWidgetItem*)));
        QObject::connect(badge3Label, SIGNAL(dropFromTreeWidgetOnEmpty(QTreeWidgetItem*)), QtConfig, SLOT(addBadge(QTreeWidgetItem*)));
        QObject::connect(badge1Label, SIGNAL(dropFromTreeWidgetOnNotEmpty(QString,QTreeWidgetItem*)), QtConfig, SLOT(swapBadge(QString,QTreeWidgetItem*)));
        QObject::connect(badge2Label, SIGNAL(dropFromTreeWidgetOnNotEmpty(QString,QTreeWidgetItem*)), QtConfig, SLOT(swapBadge(QString,QTreeWidgetItem*)));
        QObject::connect(badge3Label, SIGNAL(dropFromTreeWidgetOnNotEmpty(QString,QTreeWidgetItem*)), QtConfig, SLOT(swapBadge(QString,QTreeWidgetItem*)));
        QObject::connect(updateCSVButton, SIGNAL(clicked()), QtConfig, SLOT(updateCSV()));

        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QMainWindow *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "CustomBadges", Q_NULLPTR));
        overwolfCheckBox->setText(QApplication::translate("QtConfig", "Overwolf", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = badgeList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("QtConfig", "Badges", Q_NULLPTR));
        badge1Box->setTitle(QApplication::translate("QtConfig", "Badge 1", Q_NULLPTR));
        badge1Label->setText(QString());
        badge3Box->setTitle(QApplication::translate("QtConfig", "Badge 3", Q_NULLPTR));
        badge3Label->setText(QString());
        badge2Box->setTitle(QApplication::translate("QtConfig", "Badge 2", Q_NULLPTR));
        badge2Label->setText(QString());
        manualBadgeOverride->setText(QApplication::translate("QtConfig", "...", Q_NULLPTR));
        updateCSVButton->setText(QApplication::translate("QtConfig", "Update Badge List", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("QtConfig", "Annehmen", Q_NULLPTR));
        rejectButton->setText(QApplication::translate("QtConfig", "Abbrechen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTCONFIGP12692_H
