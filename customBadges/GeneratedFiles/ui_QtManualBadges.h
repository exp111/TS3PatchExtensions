/********************************************************************************
** Form generated from reading UI file 'QtManualBadgesmU6568.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTMANUALBADGESMU6568_H
#define QTMANUALBADGESMU6568_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BadgesWindow
{
public:
    QWidget *centralwidget;
    QPushButton *closeButton;
    QPushButton *addButton;

    void setupUi(QMainWindow *BadgesWindow)
    {
        if (BadgesWindow->objectName().isEmpty())
            BadgesWindow->setObjectName(QStringLiteral("BadgesWindow"));
        BadgesWindow->resize(251, 157);
        centralwidget = new QWidget(BadgesWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(90, 130, 75, 23));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(214, 130, 31, 23));
        BadgesWindow->setCentralWidget(centralwidget);

        retranslateUi(BadgesWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), BadgesWindow, SLOT(close()));
        QObject::connect(closeButton, SIGNAL(clicked()), BadgesWindow, SLOT(saveToConfig()));
        QObject::connect(addButton, SIGNAL(clicked()), BadgesWindow, SLOT(addBadge()));

        QMetaObject::connectSlotsByName(BadgesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BadgesWindow)
    {
        BadgesWindow->setWindowTitle(QApplication::translate("BadgesWindow", "Badges", Q_NULLPTR));
        closeButton->setText(QApplication::translate("BadgesWindow", "Close", Q_NULLPTR));
        addButton->setText(QApplication::translate("BadgesWindow", "+", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BadgesWindow: public Ui_BadgesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTMANUALBADGESMU6568_H
