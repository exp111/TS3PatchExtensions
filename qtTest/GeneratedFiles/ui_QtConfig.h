/********************************************************************************
** Form generated from reading UI file 'QtConfigHp6000.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTCONFIGHP6000_H
#define QTCONFIGHP6000_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConfig
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTreeWidget *treeWidget;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QToolBox *toolBox;
    QWidget *page;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_3;
    QSpinBox *spinBox;
    QWidget *page_2;
    QSlider *verticalSlider;
    QDial *dial;
    QLabel *label;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QWidget *page_4;
    QLabel *label_2;
    QComboBox *comboBox;
    QGroupBox *groupBox_3;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;
    QGroupBox *groupBox_4;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QFontComboBox *fontComboBox;
    QMdiArea *mdiArea;
    QWidget *subwindow;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *QtConfig)
    {
        if (QtConfig->objectName().isEmpty())
            QtConfig->setObjectName(QStringLiteral("QtConfig"));
        QtConfig->resize(771, 446);
        pushButton = new QPushButton(QtConfig);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 410, 101, 23));
        pushButton->setCheckable(false);
        pushButton_2 = new QPushButton(QtConfig);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 410, 101, 23));
        groupBox = new QGroupBox(QtConfig);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 120, 80));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 30, 70, 17));
        checkBox->setToolTipDuration(10);
        buttonBox = new QDialogButtonBox(QtConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(460, 410, 241, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Help|QDialogButtonBox::No|QDialogButtonBox::Yes);
        tabWidget = new QTabWidget(QtConfig);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(160, 10, 221, 161));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        treeWidget = new QTreeWidget(tab);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(20, 10, 151, 101));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 10, 211, 101));
        tabWidget->addTab(tab_2, QString());
        toolBox = new QToolBox(QtConfig);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(400, 10, 69, 151));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 69, 97));
        checkBox_2 = new QCheckBox(page);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 10, 70, 17));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 40, 61, 23));
        spinBox = new QSpinBox(page);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(10, 70, 42, 22));
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 69, 97));
        verticalSlider = new QSlider(page_2);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(20, 0, 22, 91));
        verticalSlider->setOrientation(Qt::Vertical);
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        dial = new QDial(QtConfig);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(180, 190, 50, 64));
        label = new QLabel(QtConfig);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        groupBox_2 = new QGroupBox(QtConfig);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 250, 120, 81));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 30, 82, 17));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 50, 82, 17));
        stackedWidget = new QStackedWidget(QtConfig);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(300, 200, 120, 80));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 30, 75, 23));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 10, 47, 13));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 47, 13));
        comboBox = new QComboBox(page_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 69, 22));
        stackedWidget->addWidget(page_4);
        groupBox_3 = new QGroupBox(QtConfig);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 130, 141, 91));
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 20, 118, 23));
        progressBar->setValue(24);
        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 60, 111, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        groupBox_4 = new QGroupBox(QtConfig);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(160, 260, 141, 131));
        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 111, 71));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 113, 20));
        fontComboBox = new QFontComboBox(QtConfig);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(30, 350, 101, 22));
        mdiArea = new QMdiArea(QtConfig);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(470, 10, 291, 161));
        subwindow = new QWidget();
        subwindow->setObjectName(QStringLiteral("subwindow"));
        mdiArea->addSubWindow(subwindow);
        calendarWidget = new QCalendarWidget(QtConfig);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(440, 190, 321, 191));

        retranslateUi(QtConfig);
        QObject::connect(pushButton, SIGNAL(clicked()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), QtConfig, SLOT(close()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QtConfig, SLOT(saveToConfig()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QtConfig, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), progressBar, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QtConfig);
    } // setupUi

    void retranslateUi(QWidget *QtConfig)
    {
        QtConfig->setWindowTitle(QApplication::translate("QtConfig", "Test Plugin", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QtConfig", "Annehmen", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("QtConfig", "Abbrechen", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QtConfig", "GroupBox", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("QtConfig", "<html><head/><body><p><span style=\" font-weight:600;\">shit</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("QtConfig", "Test", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("QtConfig", "2", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("QtConfig", "1", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("QtConfig", "2", Q_NULLPTR));
        ___qtreewidgetitem1->setText(0, QApplication::translate("QtConfig", "Neues Element", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(1, QApplication::translate("QtConfig", "2", Q_NULLPTR));
        ___qtreewidgetitem2->setText(0, QApplication::translate("QtConfig", "Neues Element", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(1, QApplication::translate("QtConfig", "3", Q_NULLPTR));
        ___qtreewidgetitem3->setText(0, QApplication::translate("QtConfig", "Neues Element", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QtConfig", "Tree", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QtConfig", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QtConfig", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("QtConfig", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("QtConfig", "2", Q_NULLPTR));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("QtConfig", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("QtConfig", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("QtConfig", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("QtConfig", "4", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QtConfig", "Table", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("QtConfig", "CheckBox", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("QtConfig", "PushButton", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("QtConfig", "Page 1", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("QtConfig", "Page 2", Q_NULLPTR));
        label->setText(QApplication::translate("QtConfig", "TextLabel", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QtConfig", "Radio Buttons", Q_NULLPTR));
        radioButton->setText(QApplication::translate("QtConfig", "RadioButton", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("QtConfig", "RadioButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("QtConfig", "PushButton", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtConfig", "2", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtConfig", "1", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QtConfig", "1", Q_NULLPTR)
         << QApplication::translate("QtConfig", "2", Q_NULLPTR)
        );
        groupBox_3->setTitle(QApplication::translate("QtConfig", "Loading Bar", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("QtConfig", "Line/Text Edit", Q_NULLPTR));
        subwindow->setWindowTitle(QApplication::translate("QtConfig", "Subwindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtConfig: public Ui_QtConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTCONFIGHP6000_H
