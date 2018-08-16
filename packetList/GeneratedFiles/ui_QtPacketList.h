/********************************************************************************
** Form generated from reading UI file 'QtPacketListp14540.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTPACKETLISTP14540_H
#define QTPACKETLISTP14540_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPacketList
{
public:
    QWidget *centralWidget;
    QGroupBox *packetInGroup;
    QTreeWidget *packetInList;
    QGroupBox *packetOutGroup;
    QTreeWidget *packetOutList;
    QPushButton *updateButton;

    void setupUi(QMainWindow *QtPacketList)
    {
        if (QtPacketList->objectName().isEmpty())
            QtPacketList->setObjectName(QStringLiteral("QtPacketList"));
        QtPacketList->resize(613, 693);
        centralWidget = new QWidget(QtPacketList);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        packetInGroup = new QGroupBox(centralWidget);
        packetInGroup->setObjectName(QStringLiteral("packetInGroup"));
        packetInGroup->setGeometry(QRect(10, 10, 591, 321));
        packetInList = new QTreeWidget(packetInGroup);
        packetInList->setObjectName(QStringLiteral("packetInList"));
        packetInList->setGeometry(QRect(10, 20, 571, 291));
        packetInList->setIndentation(0);
        packetInList->header()->setVisible(false);
        packetOutGroup = new QGroupBox(centralWidget);
        packetOutGroup->setObjectName(QStringLiteral("packetOutGroup"));
        packetOutGroup->setGeometry(QRect(10, 340, 591, 321));
        packetOutList = new QTreeWidget(packetOutGroup);
        packetOutList->setObjectName(QStringLiteral("packetOutList"));
        packetOutList->setGeometry(QRect(10, 20, 571, 291));
        packetOutList->setIndentation(0);
        packetOutList->header()->setVisible(false);
        updateButton = new QPushButton(centralWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(525, 665, 75, 23));
        QtPacketList->setCentralWidget(centralWidget);

        retranslateUi(QtPacketList);
        QObject::connect(updateButton, SIGNAL(clicked()), QtPacketList, SLOT(updateLists()));
        QObject::connect(packetInList, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), QtPacketList, SLOT(copyTextToClipboard(QTreeWidgetItem*,int)));
        QObject::connect(packetOutList, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), QtPacketList, SLOT(copyTextToClipboard(QTreeWidgetItem*,int)));

        QMetaObject::connectSlotsByName(QtPacketList);
    } // setupUi

    void retranslateUi(QMainWindow *QtPacketList)
    {
        QtPacketList->setWindowTitle(QApplication::translate("QtPacketList", "Packet List", Q_NULLPTR));
        packetInGroup->setTitle(QApplication::translate("QtPacketList", "Packet In", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = packetInList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("QtPacketList", "1", Q_NULLPTR));
        packetOutGroup->setTitle(QApplication::translate("QtPacketList", "Packet Out", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = packetOutList->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("QtPacketList", "1", Q_NULLPTR));
        updateButton->setText(QApplication::translate("QtPacketList", "Update", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtPacketList: public Ui_QtPacketList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTPACKETLISTP14540_H
