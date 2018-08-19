/********************************************************************************
** Form generated from reading UI file 'QtPacketListmU7328.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTPACKETLISTMU7328_H
#define QTPACKETLISTMU7328_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPacketList
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *packetListTab;
    QGroupBox *packetInGroup;
    QTreeWidget *packetInList;
    QGroupBox *packetOutGroup;
    QTreeWidget *packetOutList;
    QPushButton *updateButton;
    QLineEdit *searchLine;
    QLabel *searchLabel;
    QCheckBox *searchCaseBox;
    QWidget *sendCommandTab;
    QLineEdit *sendCommandLine;
    QPushButton *sendButton;
    QSpinBox *sendSchidSpin;
    QLabel *sendSchidLabel;

    void setupUi(QMainWindow *QtPacketList)
    {
        if (QtPacketList->objectName().isEmpty())
            QtPacketList->setObjectName(QStringLiteral("QtPacketList"));
        QtPacketList->resize(641, 738);
        centralWidget = new QWidget(QtPacketList);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 621, 717));
        packetListTab = new QWidget();
        packetListTab->setObjectName(QStringLiteral("packetListTab"));
        packetInGroup = new QGroupBox(packetListTab);
        packetInGroup->setObjectName(QStringLiteral("packetInGroup"));
        packetInGroup->setGeometry(QRect(10, 10, 591, 321));
        packetInList = new QTreeWidget(packetInGroup);
        packetInList->setObjectName(QStringLiteral("packetInList"));
        packetInList->setGeometry(QRect(10, 20, 571, 291));
        packetInList->setIndentation(0);
        packetInList->setExpandsOnDoubleClick(false);
        packetInList->header()->setVisible(false);
        packetOutGroup = new QGroupBox(packetListTab);
        packetOutGroup->setObjectName(QStringLiteral("packetOutGroup"));
        packetOutGroup->setGeometry(QRect(10, 340, 591, 321));
        packetOutList = new QTreeWidget(packetOutGroup);
        packetOutList->setObjectName(QStringLiteral("packetOutList"));
        packetOutList->setGeometry(QRect(10, 20, 571, 291));
        packetOutList->setIndentation(0);
        packetOutList->header()->setVisible(false);
        updateButton = new QPushButton(packetListTab);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(10, 665, 75, 23));
        searchLine = new QLineEdit(packetListTab);
        searchLine->setObjectName(QStringLiteral("searchLine"));
        searchLine->setGeometry(QRect(290, 665, 311, 23));
        searchLabel = new QLabel(packetListTab);
        searchLabel->setObjectName(QStringLiteral("searchLabel"));
        searchLabel->setGeometry(QRect(240, 665, 61, 23));
        searchCaseBox = new QCheckBox(packetListTab);
        searchCaseBox->setObjectName(QStringLiteral("searchCaseBox"));
        searchCaseBox->setGeometry(QRect(130, 665, 141, 23));
        tabWidget->addTab(packetListTab, QString());
        sendCommandTab = new QWidget();
        sendCommandTab->setObjectName(QStringLiteral("sendCommandTab"));
        sendCommandLine = new QLineEdit(sendCommandTab);
        sendCommandLine->setObjectName(QStringLiteral("sendCommandLine"));
        sendCommandLine->setGeometry(QRect(10, 10, 591, 20));
        sendButton = new QPushButton(sendCommandTab);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(10, 40, 75, 23));
        sendSchidSpin = new QSpinBox(sendCommandTab);
        sendSchidSpin->setObjectName(QStringLiteral("sendSchidSpin"));
        sendSchidSpin->setGeometry(QRect(560, 40, 42, 22));
        sendSchidSpin->setMinimum(1);
        sendSchidLabel = new QLabel(sendCommandTab);
        sendSchidLabel->setObjectName(QStringLiteral("sendSchidLabel"));
        sendSchidLabel->setGeometry(QRect(400, 40, 151, 20));
        tabWidget->addTab(sendCommandTab, QString());
        QtPacketList->setCentralWidget(centralWidget);

        retranslateUi(QtPacketList);
        QObject::connect(updateButton, SIGNAL(clicked()), QtPacketList, SLOT(updateLists()));
        QObject::connect(packetInList, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), QtPacketList, SLOT(copyTextToClipboard(QTreeWidgetItem*)));
        QObject::connect(packetOutList, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), QtPacketList, SLOT(copyTextToClipboard(QTreeWidgetItem*)));
        QObject::connect(sendButton, SIGNAL(clicked()), QtPacketList, SLOT(sendCommand()));
        QObject::connect(sendCommandLine, SIGNAL(textChanged(QString)), QtPacketList, SLOT(checkSendButton()));
        QObject::connect(searchLine, SIGNAL(textChanged(QString)), QtPacketList, SLOT(updateLists()));
        QObject::connect(searchCaseBox, SIGNAL(stateChanged(int)), QtPacketList, SLOT(updateLists()));

        tabWidget->setCurrentIndex(0);


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
        searchLabel->setText(QApplication::translate("QtPacketList", "Search:", Q_NULLPTR));
        searchCaseBox->setText(QApplication::translate("QtPacketList", "Case Sensitive", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(packetListTab), QApplication::translate("QtPacketList", "Packet List", Q_NULLPTR));
        sendButton->setText(QApplication::translate("QtPacketList", "Send", Q_NULLPTR));
        sendSchidLabel->setText(QApplication::translate("QtPacketList", "ServerConnectionHandlerID:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(sendCommandTab), QApplication::translate("QtPacketList", "Send Packet", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtPacketList: public Ui_QtPacketList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTPACKETLISTMU7328_H
