/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEditName;
    QLabel *labelName_2;
    QSpinBox *spinBoxAge;
    QPushButton *buttonSubmit;
    QPushButton *buttonToPage2;
    QLabel *label_5;
    QLabel *label;
    QWidget *page_3;
    QComboBox *comboBoxEatingHabits;
    QComboBox *comboBoxWorkoutPreferences;
    QTextEdit *workoutPlanTextEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *generateWorkoutButton;
    QPushButton *buttonToPage3;
    QWidget *page_2;
    QTextEdit *clockModeTextEdit;
    QLabel *clockModeLabel;
    QTextEdit *heartRateTextEdit;
    QLabel *heartRateLabel;
    QLabel *stepCountLabel;
    QTextEdit *stepCountTextEdit;
    QPushButton *buttonStartTimer;
    QPushButton *heartRateButton;
    QLabel *inclineLabel;
    QTextEdit *inclineTextEdit;
    QLabel *speedLabel;
    QTextEdit *fanSpeedTextEdit;
    QLabel *resistanceLabel;
    QTextEdit *resistanceTextEdit;
    QPushButton *increaseInclineButton;
    QPushButton *decreaseInclineButton;
    QPushButton *increaseFanButton;
    QPushButton *decreaseFanButton;
    QPushButton *fanButton;
    QPushButton *increaseResistanceButton;
    QPushButton *decreaseResistanceButton;
    QTextEdit *distanceTextEdit;
    QLabel *distanceLabel;
    QLabel *caloriesLabel;
    QTextEdit *caloriesTextEdit;
    QPushButton *buttonShowDistance;
    QTextEdit *activityLog;
    QPushButton *buttonToPage1;
    QLabel *labelDisplayAge;
    QLabel *labelDisplayName;
    QPushButton *buttonStopTimer;
    QPushButton *buttonShowCalories;
    QPushButton *buttonShowSteps;
    QSpinBox *spinBoxCountdown;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(80, 0, 701, 471));
        page = new QWidget();
        page->setObjectName("page");
        lineEditName = new QLineEdit(page);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(290, 250, 91, 21));
        labelName_2 = new QLabel(page);
        labelName_2->setObjectName("labelName_2");
        labelName_2->setGeometry(QRect(310, 230, 58, 16));
        spinBoxAge = new QSpinBox(page);
        spinBoxAge->setObjectName("spinBoxAge");
        spinBoxAge->setGeometry(QRect(410, 250, 42, 22));
        buttonSubmit = new QPushButton(page);
        buttonSubmit->setObjectName("buttonSubmit");
        buttonSubmit->setGeometry(QRect(320, 290, 100, 32));
        buttonToPage2 = new QPushButton(page);
        buttonToPage2->setObjectName("buttonToPage2");
        buttonToPage2->setGeometry(QRect(570, 40, 100, 32));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(410, 230, 58, 16));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 110, 91, 111));
        label->setPixmap(QPixmap(QString::fromUtf8("../Pictures/34.jpg")));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        comboBoxEatingHabits = new QComboBox(page_3);
        comboBoxEatingHabits->addItem(QString());
        comboBoxEatingHabits->addItem(QString());
        comboBoxEatingHabits->addItem(QString());
        comboBoxEatingHabits->setObjectName("comboBoxEatingHabits");
        comboBoxEatingHabits->setGeometry(QRect(340, 180, 103, 32));
        comboBoxWorkoutPreferences = new QComboBox(page_3);
        comboBoxWorkoutPreferences->addItem(QString());
        comboBoxWorkoutPreferences->addItem(QString());
        comboBoxWorkoutPreferences->addItem(QString());
        comboBoxWorkoutPreferences->setObjectName("comboBoxWorkoutPreferences");
        comboBoxWorkoutPreferences->setGeometry(QRect(520, 180, 103, 32));
        workoutPlanTextEdit = new QTextEdit(page_3);
        workoutPlanTextEdit->setObjectName("workoutPlanTextEdit");
        workoutPlanTextEdit->setGeometry(QRect(110, 280, 541, 201));
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 240, 171, 16));
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(540, 140, 131, 16));
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(350, 150, 91, 16));
        generateWorkoutButton = new QPushButton(page_3);
        generateWorkoutButton->setObjectName("generateWorkoutButton");
        generateWorkoutButton->setGeometry(QRect(220, 70, 131, 32));
        buttonToPage3 = new QPushButton(page_3);
        buttonToPage3->setObjectName("buttonToPage3");
        buttonToPage3->setGeometry(QRect(520, 30, 100, 32));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        clockModeTextEdit = new QTextEdit(page_2);
        clockModeTextEdit->setObjectName("clockModeTextEdit");
        clockModeTextEdit->setGeometry(QRect(180, 70, 81, 31));
        clockModeLabel = new QLabel(page_2);
        clockModeLabel->setObjectName("clockModeLabel");
        clockModeLabel->setGeometry(QRect(180, 50, 81, 21));
        heartRateTextEdit = new QTextEdit(page_2);
        heartRateTextEdit->setObjectName("heartRateTextEdit");
        heartRateTextEdit->setGeometry(QRect(360, 70, 81, 31));
        heartRateLabel = new QLabel(page_2);
        heartRateLabel->setObjectName("heartRateLabel");
        heartRateLabel->setGeometry(QRect(360, 50, 81, 21));
        stepCountLabel = new QLabel(page_2);
        stepCountLabel->setObjectName("stepCountLabel");
        stepCountLabel->setGeometry(QRect(580, 50, 81, 21));
        stepCountTextEdit = new QTextEdit(page_2);
        stepCountTextEdit->setObjectName("stepCountTextEdit");
        stepCountTextEdit->setGeometry(QRect(580, 70, 71, 31));
        buttonStartTimer = new QPushButton(page_2);
        buttonStartTimer->setObjectName("buttonStartTimer");
        buttonStartTimer->setGeometry(QRect(70, 110, 101, 32));
        heartRateButton = new QPushButton(page_2);
        heartRateButton->setObjectName("heartRateButton");
        heartRateButton->setGeometry(QRect(360, 110, 81, 32));
        inclineLabel = new QLabel(page_2);
        inclineLabel->setObjectName("inclineLabel");
        inclineLabel->setGeometry(QRect(180, 160, 71, 21));
        inclineTextEdit = new QTextEdit(page_2);
        inclineTextEdit->setObjectName("inclineTextEdit");
        inclineTextEdit->setGeometry(QRect(180, 180, 81, 31));
        speedLabel = new QLabel(page_2);
        speedLabel->setObjectName("speedLabel");
        speedLabel->setGeometry(QRect(380, 160, 41, 21));
        fanSpeedTextEdit = new QTextEdit(page_2);
        fanSpeedTextEdit->setObjectName("fanSpeedTextEdit");
        fanSpeedTextEdit->setGeometry(QRect(380, 180, 91, 31));
        resistanceLabel = new QLabel(page_2);
        resistanceLabel->setObjectName("resistanceLabel");
        resistanceLabel->setGeometry(QRect(580, 160, 71, 21));
        resistanceTextEdit = new QTextEdit(page_2);
        resistanceTextEdit->setObjectName("resistanceTextEdit");
        resistanceTextEdit->setGeometry(QRect(580, 180, 91, 31));
        increaseInclineButton = new QPushButton(page_2);
        increaseInclineButton->setObjectName("increaseInclineButton");
        increaseInclineButton->setGeometry(QRect(100, 180, 71, 32));
        decreaseInclineButton = new QPushButton(page_2);
        decreaseInclineButton->setObjectName("decreaseInclineButton");
        decreaseInclineButton->setGeometry(QRect(100, 220, 71, 32));
        increaseFanButton = new QPushButton(page_2);
        increaseFanButton->setObjectName("increaseFanButton");
        increaseFanButton->setGeometry(QRect(290, 180, 81, 32));
        decreaseFanButton = new QPushButton(page_2);
        decreaseFanButton->setObjectName("decreaseFanButton");
        decreaseFanButton->setGeometry(QRect(290, 220, 81, 32));
        fanButton = new QPushButton(page_2);
        fanButton->setObjectName("fanButton");
        fanButton->setGeometry(QRect(290, 260, 81, 32));
        increaseResistanceButton = new QPushButton(page_2);
        increaseResistanceButton->setObjectName("increaseResistanceButton");
        increaseResistanceButton->setGeometry(QRect(500, 180, 71, 32));
        decreaseResistanceButton = new QPushButton(page_2);
        decreaseResistanceButton->setObjectName("decreaseResistanceButton");
        decreaseResistanceButton->setGeometry(QRect(500, 220, 71, 32));
        distanceTextEdit = new QTextEdit(page_2);
        distanceTextEdit->setObjectName("distanceTextEdit");
        distanceTextEdit->setGeometry(QRect(500, 330, 81, 31));
        distanceLabel = new QLabel(page_2);
        distanceLabel->setObjectName("distanceLabel");
        distanceLabel->setGeometry(QRect(430, 330, 61, 21));
        caloriesLabel = new QLabel(page_2);
        caloriesLabel->setObjectName("caloriesLabel");
        caloriesLabel->setGeometry(QRect(430, 370, 61, 21));
        caloriesTextEdit = new QTextEdit(page_2);
        caloriesTextEdit->setObjectName("caloriesTextEdit");
        caloriesTextEdit->setGeometry(QRect(500, 370, 81, 31));
        buttonShowDistance = new QPushButton(page_2);
        buttonShowDistance->setObjectName("buttonShowDistance");
        buttonShowDistance->setGeometry(QRect(590, 330, 100, 32));
        activityLog = new QTextEdit(page_2);
        activityLog->setObjectName("activityLog");
        activityLog->setGeometry(QRect(30, 390, 271, 74));
        buttonToPage1 = new QPushButton(page_2);
        buttonToPage1->setObjectName("buttonToPage1");
        buttonToPage1->setGeometry(QRect(590, 430, 100, 31));
        labelDisplayAge = new QLabel(page_2);
        labelDisplayAge->setObjectName("labelDisplayAge");
        labelDisplayAge->setGeometry(QRect(0, 10, 58, 16));
        labelDisplayName = new QLabel(page_2);
        labelDisplayName->setObjectName("labelDisplayName");
        labelDisplayName->setGeometry(QRect(0, 40, 191, 20));
        buttonStopTimer = new QPushButton(page_2);
        buttonStopTimer->setObjectName("buttonStopTimer");
        buttonStopTimer->setGeometry(QRect(70, 70, 100, 32));
        buttonShowCalories = new QPushButton(page_2);
        buttonShowCalories->setObjectName("buttonShowCalories");
        buttonShowCalories->setGeometry(QRect(590, 370, 100, 32));
        buttonShowSteps = new QPushButton(page_2);
        buttonShowSteps->setObjectName("buttonShowSteps");
        buttonShowSteps->setGeometry(QRect(470, 70, 100, 32));
        spinBoxCountdown = new QSpinBox(page_2);
        spinBoxCountdown->setObjectName("spinBoxCountdown");
        spinBoxCountdown->setGeometry(QRect(180, 100, 81, 22));
        spinBoxCountdown->setMinimum(1);
        spinBoxCountdown->setMaximum(3600);
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 20, 51, 51));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../Downloads/Pre1.png")));
        label_6->setScaledContents(true);
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelName_2->setText(QCoreApplication::translate("MainWindow", "NAME", nullptr));
        buttonSubmit->setText(QCoreApplication::translate("MainWindow", "SUBMIT", nullptr));
        buttonToPage2->setText(QCoreApplication::translate("MainWindow", "Next Page", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Age:", nullptr));
        label->setText(QString());
        comboBoxEatingHabits->setItemText(0, QCoreApplication::translate("MainWindow", "Healthy", nullptr));
        comboBoxEatingHabits->setItemText(1, QCoreApplication::translate("MainWindow", "Moderate", nullptr));
        comboBoxEatingHabits->setItemText(2, QCoreApplication::translate("MainWindow", "Unhealthy", nullptr));

        comboBoxWorkoutPreferences->setItemText(0, QCoreApplication::translate("MainWindow", "Cardio", nullptr));
        comboBoxWorkoutPreferences->setItemText(1, QCoreApplication::translate("MainWindow", "Strength", nullptr));
        comboBoxWorkoutPreferences->setItemText(2, QCoreApplication::translate("MainWindow", "Mixed", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Workout Suggestions", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Workout Preferences", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Eating Habits", nullptr));
        generateWorkoutButton->setText(QCoreApplication::translate("MainWindow", "Generate Workout", nullptr));
        buttonToPage3->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        clockModeLabel->setText(QCoreApplication::translate("MainWindow", "Clock Mode", nullptr));
        heartRateLabel->setText(QCoreApplication::translate("MainWindow", "Heart Rate:", nullptr));
        stepCountLabel->setText(QCoreApplication::translate("MainWindow", "Step Count", nullptr));
        buttonStartTimer->setText(QCoreApplication::translate("MainWindow", "Start Timer", nullptr));
        heartRateButton->setText(QCoreApplication::translate("MainWindow", "Start/Stop", nullptr));
        inclineLabel->setText(QCoreApplication::translate("MainWindow", "Incline", nullptr));
        speedLabel->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        resistanceLabel->setText(QCoreApplication::translate("MainWindow", "Resistance", nullptr));
        increaseInclineButton->setText(QCoreApplication::translate("MainWindow", "   Increase  ", nullptr));
        decreaseInclineButton->setText(QCoreApplication::translate("MainWindow", "  Decrease ", nullptr));
        increaseFanButton->setText(QCoreApplication::translate("MainWindow", "Increase ", nullptr));
        decreaseFanButton->setText(QCoreApplication::translate("MainWindow", "Decrease ", nullptr));
        fanButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        increaseResistanceButton->setText(QCoreApplication::translate("MainWindow", "Increase ", nullptr));
        decreaseResistanceButton->setText(QCoreApplication::translate("MainWindow", "Decrease ", nullptr));
        distanceLabel->setText(QCoreApplication::translate("MainWindow", "Distance: ", nullptr));
        caloriesLabel->setText(QCoreApplication::translate("MainWindow", "Calories:", nullptr));
        buttonShowDistance->setText(QCoreApplication::translate("MainWindow", "Show Distance", nullptr));
        buttonToPage1->setText(QCoreApplication::translate("MainWindow", "Previous page", nullptr));
        labelDisplayAge->setText(QCoreApplication::translate("MainWindow", "AGE:", nullptr));
        labelDisplayName->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        buttonStopTimer->setText(QCoreApplication::translate("MainWindow", "Stop Timer", nullptr));
        buttonShowCalories->setText(QCoreApplication::translate("MainWindow", "Show Calories", nullptr));
        buttonShowSteps->setText(QCoreApplication::translate("MainWindow", "Show Steps", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
