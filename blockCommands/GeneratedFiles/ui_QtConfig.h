/********************************************************************************
** Form generated from reading UI file 'QtConfigHp9148.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTCONFIGHP9148_H
#define QTCONFIGHP9148_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConfig
{
public:
    QGroupBox *commandInGroup;
    QTreeWidget *commandInList;
    QLineEdit *commandInLine;
    QToolButton *commandInAddButton;
    QToolButton *commandInDeleteButton;
    QPushButton *acceptButton;
    QPushButton *cancelButton;
    QGroupBox *commandOutGroup;
    QTreeWidget *commandOutList;
    QLineEdit *commandOutLine;
    QToolButton *commandOutAddButton;
    QToolButton *commandOutDeleteButton;

    void setupUi(QWidget *QtConfig)
    {
        if (QtConfig->objectName().isEmpty())
            QtConfig->setObjectName(QStringLiteral("QtConfig"));
        QtConfig->resize(690, 439);
        commandInGroup = new QGroupBox(QtConfig);
        commandInGroup->setObjectName(QStringLiteral("commandInGroup"));
        commandInGroup->setGeometry(QRect(10, 10, 331, 391));
        commandInList = new QTreeWidget(commandInGroup);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        commandInList->setHeaderItem(__qtreewidgetitem);
        commandInList->setObjectName(QStringLiteral("commandInList"));
        commandInList->setGeometry(QRect(10, 20, 311, 301));
        commandInList->setIndentation(0);
        commandInList->header()->setVisible(false);
        commandInLine = new QLineEdit(commandInGroup);
        commandInLine->setObjectName(QStringLiteral("commandInLine"));
        commandInLine->setGeometry(QRect(10, 360, 311, 20));
        commandInAddButton = new QToolButton(commandInGroup);
        commandInAddButton->setObjectName(QStringLiteral("commandInAddButton"));
        commandInAddButton->setGeometry(QRect(130, 330, 25, 19));
        commandInAddButton->setArrowType(Qt::UpArrow);
        commandInDeleteButton = new QToolButton(commandInGroup);
        commandInDeleteButton->setObjectName(QStringLiteral("commandInDeleteButton"));
        commandInDeleteButton->setGeometry(QRect(170, 330, 25, 19));
        commandInDeleteButton->setAutoRaise(false);
        commandInDeleteButton->setArrowType(Qt::DownArrow);
        acceptButton = new QPushButton(QtConfig);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(100, 410, 151, 23));
        cancelButton = new QPushButton(QtConfig);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(430, 410, 151, 23));
        commandOutGroup = new QGroupBox(QtConfig);
        commandOutGroup->setObjectName(QStringLiteral("commandOutGroup"));
        commandOutGroup->setGeometry(QRect(340, 10, 331, 391));
        commandOutList = new QTreeWidget(commandOutGroup);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        commandOutList->setHeaderItem(__qtreewidgetitem1);
        commandOutList->setObjectName(QStringLiteral("commandOutList"));
        commandOutList->setGeometry(QRect(10, 20, 311, 301));
        commandOutList->setIndentation(0);
        commandOutList->header()->setVisible(false);
        commandOutLine = new QLineEdit(commandOutGroup);
        commandOutLine->setObjectName(QStringLiteral("commandOutLine"));
        commandOutLine->setGeometry(QRect(10, 360, 311, 20));
        commandOutAddButton = new QToolButton(commandOutGroup);
        commandOutAddButton->setObjectName(QStringLiteral("commandOutAddButton"));
        commandOutAddButton->setGeometry(QRect(130, 330, 25, 19));
        commandOutAddButton->setArrowType(Qt::UpArrow);
        commandOutDeleteButton = new QToolButton(commandOutGroup);
        commandOutDeleteButton->setObjectName(QStringLiteral("commandOutDeleteButton"));
        commandOutDeleteButton->setGeometry(QRect(170, 330, 25, 19));
        commandOutDeleteButton->setAutoRaise(false);
        commandOutDeleteButton->setArrowType(Qt::DownArrow);

        retranslateUi(QtConfig);
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(cancelButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(commandInLine, SIGNAL(textChanged(QString)), QtConfig, SLOT(checkInAddButton()));
        QObject::connect(commandOutLine, SIGNAL(textChanged(QString)), QtConfig, SLOT(checkOutAddButton()));
        QObject::connect(commandInAddButton, SIGNAL(clicked()), QtConfig, SLOT(commandInAdd()));
        QObject::connect(commandOutAddButton, SIGNAL(clicked()), QtConfig, SLOT(commandOutAdd()));
        QObject::connect(commandInDeleteButton, SIGNAL(clicked()), QtConfig, SLOT(commandInDelete()));
        QObject::connect(commandOutDeleteButton, SIGNAL(clicked()), QtConfig, SLOT(commandOutDelete()));

        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QWidget *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "Block Commands", Q_NULLPTR));
        commandInGroup->setTitle(QApplication::translate("QtConfig", "Command In", Q_NULLPTR));
        commandInAddButton->setText(QApplication::translate("QtConfig", "...", Q_NULLPTR));
        commandInDeleteButton->setText(QApplication::translate("QtConfig", "...", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("QtConfig", "Accept", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("QtConfig", "Cancel", Q_NULLPTR));
        commandOutGroup->setTitle(QApplication::translate("QtConfig", "Command Out", Q_NULLPTR));
        commandOutAddButton->setText(QApplication::translate("QtConfig", "...", Q_NULLPTR));
        commandOutDeleteButton->setText(QApplication::translate("QtConfig", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTCONFIGHP9148_H
