/********************************************************************************
** Form generated from reading UI file 'QtConfigHp1076.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTCONFIGHP1076_H
#define QTCONFIGHP1076_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConfig
{
public:
    QPushButton *acceptButton;
    QPushButton *cancelButton;
    QLabel *hostMessageLabel;
    QLabel *modeLabel;
    QLineEdit *hostMessageLine;
    QSpinBox *hostModeSpin;

    void setupUi(QWidget *QtConfig)
    {
        if (QtConfig->objectName().isEmpty())
            QtConfig->setObjectName(QStringLiteral("QtConfig"));
        QtConfig->resize(348, 93);
        QtConfig->setMinimumSize(QSize(0, 0));
        QtConfig->setContextMenuPolicy(Qt::NoContextMenu);
        acceptButton = new QPushButton(QtConfig);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(20, 60, 111, 23));
        acceptButton->setCheckable(false);
        cancelButton = new QPushButton(QtConfig);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(220, 60, 111, 23));
        hostMessageLabel = new QLabel(QtConfig);
        hostMessageLabel->setObjectName(QStringLiteral("hostMessageLabel"));
        hostMessageLabel->setGeometry(QRect(20, 10, 111, 16));
        modeLabel = new QLabel(QtConfig);
        modeLabel->setObjectName(QStringLiteral("modeLabel"));
        modeLabel->setGeometry(QRect(260, 10, 81, 16));
        hostMessageLine = new QLineEdit(QtConfig);
        hostMessageLine->setObjectName(QStringLiteral("hostMessageLine"));
        hostMessageLine->setGeometry(QRect(20, 30, 231, 22));
        hostModeSpin = new QSpinBox(QtConfig);
        hostModeSpin->setObjectName(QStringLiteral("hostModeSpin"));
        hostModeSpin->setGeometry(QRect(260, 30, 71, 22));
        hostModeSpin->setMaximum(3);

        retranslateUi(QtConfig);
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(cancelButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(close()));

        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QWidget *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "Modal Quit Bypass", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("QtConfig", "Annehmen", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("QtConfig", "Abbrechen", Q_NULLPTR));
        hostMessageLabel->setText(QApplication::translate("QtConfig", "Hostmessage", Q_NULLPTR));
        modeLabel->setText(QApplication::translate("QtConfig", "Mode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTCONFIGHP1076_H
