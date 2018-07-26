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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConfig
{
public:
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;

    void setupUi(QWidget *QtConfig)
    {
        if (QtConfig->objectName().isEmpty())
            QtConfig->setObjectName(QStringLiteral("QtConfig"));
        QtConfig->resize(284, 205);
        pushButton = new QPushButton(QtConfig);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(24, 140, 101, 23));
        pushButton->setCheckable(false);
        checkBox = new QCheckBox(QtConfig);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(40, 50, 70, 17));
        checkBox->setToolTipDuration(10);
        pushButton_2 = new QPushButton(QtConfig);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 140, 101, 23));

        retranslateUi(QtConfig);
        QObject::connect(pushButton, SIGNAL(clicked()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), QtConfig, SLOT(close()));

        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QWidget *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "Test Plugin", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QtConfig", "Annehmen", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("QtConfig", "<html><head/><body><p><span style=\" font-weight:600;\">shit</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("QtConfig", "Test", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("QtConfig", "Abbrechen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCONFIG_H
