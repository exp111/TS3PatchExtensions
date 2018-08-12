/********************************************************************************
** Form generated from reading UI file 'QtConfigHp8196.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTCONFIGHP8196_H
#define QTCONFIGHP8196_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConfig
{
public:
    QPushButton *acceptButton;
    QPushButton *cancelButton;
    QComboBox *OSComboBox;
    QLabel *OSLabel;
    QLabel *versionLabel;
    QComboBox *versionComboBox;

    void setupUi(QWidget *QtConfig)
    {
        if (QtConfig->objectName().isEmpty())
            QtConfig->setObjectName(QStringLiteral("QtConfig"));
        QtConfig->resize(348, 123);
        QtConfig->setMinimumSize(QSize(0, 0));
        QtConfig->setContextMenuPolicy(Qt::NoContextMenu);
        acceptButton = new QPushButton(QtConfig);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(20, 80, 111, 23));
        acceptButton->setCheckable(false);
        cancelButton = new QPushButton(QtConfig);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(220, 80, 111, 23));
        OSComboBox = new QComboBox(QtConfig);
        OSComboBox->setObjectName(QStringLiteral("OSComboBox"));
        OSComboBox->setGeometry(QRect(20, 40, 131, 22));
        OSLabel = new QLabel(QtConfig);
        OSLabel->setObjectName(QStringLiteral("OSLabel"));
        OSLabel->setGeometry(QRect(20, 20, 111, 16));
        versionLabel = new QLabel(QtConfig);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setGeometry(QRect(160, 20, 111, 16));
        versionComboBox = new QComboBox(QtConfig);
        versionComboBox->setObjectName(QStringLiteral("versionComboBox"));
        versionComboBox->setGeometry(QRect(160, 40, 171, 22));

        retranslateUi(QtConfig);
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(cancelButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(acceptButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(OSComboBox, SIGNAL(currentIndexChanged(QString)), QtConfig, SLOT(updateVersionCombo(QString)));

        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QWidget *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "Version & OS Spoofer", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("QtConfig", "Annehmen", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("QtConfig", "Abbrechen", Q_NULLPTR));
        OSLabel->setText(QApplication::translate("QtConfig", "OS", Q_NULLPTR));
        versionLabel->setText(QApplication::translate("QtConfig", "Version", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTCONFIGHP8196_H
