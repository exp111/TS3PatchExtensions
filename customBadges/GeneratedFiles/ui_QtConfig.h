/********************************************************************************
** Form generated from reading UI file 'QtConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCONFIG_H
#define UI_QTCONFIG_H

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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/badge/icons/addon_author.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/badge/icons/addon_author_bronze.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/badge/icons/addon_author_silver.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/badge/icons/addon_author_gold.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/badge/icons/gamescom_2014.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/badge/icons/gamescom_2016.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/badge/icons/gamescom_2017.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/badge/icons/hero_2017.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/badge/icons/paris_gamesweek_2014.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/badge/icons/paris_gamesweek_2016.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/badge/icons/mifcom.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/badge/icons/4netplayers.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/badge/icons/rbtv.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/badge/icons/ts_early_2018.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/badge/icons/ts_2018.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/badge/icons/e3_2018.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem1->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem2->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem3->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem4->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem5->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem6->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem7->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem8->setIcon(0, icon9);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem9->setIcon(0, icon10);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem10->setIcon(0, icon11);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem11->setIcon(0, icon12);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem12->setIcon(0, icon13);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem13->setIcon(0, icon14);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem14->setIcon(0, icon15);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(badgeList);
        __qtreewidgetitem15->setIcon(0, icon16);
        badgeList->setObjectName(QStringLiteral("badgeList"));
        badgeList->setGeometry(QRect(50, 120, 431, 241));
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

        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QMainWindow *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "TS3Hook", Q_NULLPTR));
        overwolfCheckBox->setText(QApplication::translate("QtConfig", "Overwolf", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = badgeList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("QtConfig", "Badges", Q_NULLPTR));

        const bool __sortingEnabled = badgeList->isSortingEnabled();
        badgeList->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = badgeList->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("QtConfig", "Addon Creator", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = badgeList->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("QtConfig", "Addon Creator Bronze", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = badgeList->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("QtConfig", "Addon Creator Silver", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = badgeList->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("QtConfig", "Addon Creator Gold", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = badgeList->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("QtConfig", "Gamescom 2014", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = badgeList->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QApplication::translate("QtConfig", "Gamescom 2016", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = badgeList->topLevelItem(6);
        ___qtreewidgetitem7->setText(0, QApplication::translate("QtConfig", "Gamescom 2017", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = badgeList->topLevelItem(7);
        ___qtreewidgetitem8->setText(0, QApplication::translate("QtConfig", "Gamescom Hero 2017", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = badgeList->topLevelItem(8);
        ___qtreewidgetitem9->setText(0, QApplication::translate("QtConfig", "Paris Games Week 2014", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = badgeList->topLevelItem(9);
        ___qtreewidgetitem10->setText(0, QApplication::translate("QtConfig", "Paris Games Week 2016", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = badgeList->topLevelItem(10);
        ___qtreewidgetitem11->setText(0, QApplication::translate("QtConfig", "MIFCOM", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = badgeList->topLevelItem(11);
        ___qtreewidgetitem12->setText(0, QApplication::translate("QtConfig", "4NetPlayers", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = badgeList->topLevelItem(12);
        ___qtreewidgetitem13->setText(0, QApplication::translate("QtConfig", "Rocket Beans TV", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = badgeList->topLevelItem(13);
        ___qtreewidgetitem14->setText(0, QApplication::translate("QtConfig", "TeamSpeak Jedi", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = badgeList->topLevelItem(14);
        ___qtreewidgetitem15->setText(0, QApplication::translate("QtConfig", "Official TeamSpeak Gamer", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = badgeList->topLevelItem(15);
        ___qtreewidgetitem16->setText(0, QApplication::translate("QtConfig", "E3 2018", Q_NULLPTR));
        badgeList->setSortingEnabled(__sortingEnabled);

        badge1Box->setTitle(QApplication::translate("QtConfig", "Badge 1", Q_NULLPTR));
        badge1Label->setText(QString());
        badge3Box->setTitle(QApplication::translate("QtConfig", "Badge 3", Q_NULLPTR));
        badge3Label->setText(QString());
        badge2Box->setTitle(QApplication::translate("QtConfig", "Badge 2", Q_NULLPTR));
        badge2Label->setText(QString());
        manualBadgeOverride->setText(QApplication::translate("QtConfig", "...", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("QtConfig", "Annehmen", Q_NULLPTR));
        rejectButton->setText(QApplication::translate("QtConfig", "Abbrechen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCONFIG_H
