#include "mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QRandomGenerator>
#include <QTime>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scadaHMI(new SCADA_HMI(this))
    , heartRateTimer(new QTimer(this))
    , clockTimer(new QTimer(this))
    , countdownTime(0) // Initialize countdown time
{
    ui->setupUi(this);

    // Initialize new widgets
    lineEditName = findChild<QLineEdit *>("lineEditName");
    spinBoxAge = findChild<QSpinBox *>("spinBoxAge");
    labelDisplayName = findChild<QLabel *>("labelDisplayName");
    labelDisplayAge = findChild<QLabel *>("labelDisplayAge");
    buttonSubmit = findChild<QPushButton *>("buttonSubmit");

    // Set the pixmap for the heart rate image
    QPixmap heartRateImage(":/path/to/your/image.png"); // Replace with the actual path to your image
    ui->label_6->setPixmap(heartRateImage);

    // Initialize incline, resistance, and fan speed levels
    ui->inclineTextEdit->setText(QString::number(0));
    ui->resistanceTextEdit->setText(QString::number(0));
    ui->fanSpeedTextEdit->setText(QString::number(1));

    // Connect the submit button to the slot
    connect(buttonSubmit, &QPushButton::clicked, this, &MainWindow::onSubmitButtonClicked);

    // Connect navigation buttons to slots
    connect(ui->buttonToPage1, &QPushButton::clicked, this, &MainWindow::showPage1);
    connect(ui->buttonToPage2, &QPushButton::clicked, this, &MainWindow::showPage2);
    connect(ui->buttonToPage3, &QPushButton::clicked, this, &MainWindow::showPage3);

    // Connect SCADA_HMI signals to update UI
    connect(scadaHMI, &SCADA_HMI::updateUI, this, &MainWindow::updateUI);

    // Connect other buttons to slots
    connect(ui->fanButton, &QPushButton::clicked, this, &MainWindow::onFanButtonClicked);
    connect(ui->increaseResistanceButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onIncreaseResistanceButtonClicked);
    connect(ui->decreaseResistanceButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onDecreaseResistanceButtonClicked);
    connect(ui->increaseInclineButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onIncreaseInclineButtonClicked);
    connect(ui->decreaseInclineButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onDecreaseInclineButtonClicked);
    connect(ui->increaseFanButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onIncreaseFanButtonClicked);
    connect(ui->decreaseFanButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onDecreaseFanButtonClicked);
    connect(ui->heartRateButton, &QPushButton::clicked, this, &MainWindow::onHeartRateButtonClicked);
    connect(ui->buttonShowDistance,
            &QPushButton::clicked,
            this,
            &MainWindow::onDistanceButtonClicked);
    connect(ui->buttonShowSteps, &QPushButton::clicked, this, &MainWindow::onShowStepsButtonClicked);
    connect(ui->buttonShowCalories,
            &QPushButton::clicked,
            this,
            &MainWindow::onShowCaloriesButtonClicked);

    // Connect start and stop timer buttons to slots
    connect(ui->buttonStartTimer, &QPushButton::clicked, this, &MainWindow::startClockTimer);
    connect(ui->buttonStopTimer, &QPushButton::clicked, this, &MainWindow::stopClockTimer);

    // Set up a timer to periodically update the heart rate
    connect(heartRateTimer, &QTimer::timeout, this, &MainWindow::updateHeartRate);

    // Set up the clock timer to update every second
    connect(clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);

    // Connect custom workout buttons to slots
    connect(ui->generateWorkoutButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onGenerateWorkoutButtonClicked);

    // Connect QSpinBox for countdown time
    connect(ui->spinBoxCountdown,
            QOverload<int>::of(&QSpinBox::valueChanged),
            this,
            &MainWindow::setCountdownTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCountdownTime(int time)
{
    countdownTime = time;
}

void MainWindow::startClockTimer()
{
    clockTimer->start(1000); // Update every second
    logActivity("Clock timer started.");
}

void MainWindow::stopClockTimer()
{
    clockTimer->stop();
    logActivity("Clock timer stopped.");
}

void MainWindow::updateClock()
{
    if (countdownTime > 0) {
        countdownTime--;
        ui->clockModeTextEdit->setText(QString::number(countdownTime));
        logActivity("Clock updated: " + QString::number(countdownTime));
    } else {
        clockTimer->stop();
        ui->clockModeTextEdit->setText("Time's up!");
        logActivity("Clock timer finished.");
    }
}

void MainWindow::updateUI(double speed,
                          int resistance,
                          int incline,
                          int heartRate,
                          int stepCount,
                          double caloriesBurned,
                          double distance,
                          QString clockMode)
{
    ui->fanSpeedTextEdit->setText(QString::number(speed)); // Update the fan speed
    ui->resistanceTextEdit->setText(QString::number(resistance));
    ui->inclineTextEdit->setText(QString::number(incline));
    ui->heartRateTextEdit->setText(QString::number(heartRate));     // Update the heart rate
    ui->stepCountTextEdit->setText(QString::number(stepCount));     // Update the step count
    ui->caloriesTextEdit->setText(QString::number(caloriesBurned)); // Update the calories burned
    ui->distanceTextEdit->setText(QString::number(distance));       // Update the distance
    ui->clockModeTextEdit->setText(clockMode);
    logActivity("UI updated with new statistics.");
}

void MainWindow::onFanButtonClicked()
{
    scadaHMI->controlFan(1);                           // Example: Set fan speed to 1
    ui->fanSpeedTextEdit->setText(QString::number(1)); // Update the fan speed
    logActivity("Fan button clicked. Fan speed set to 1.");
}

void MainWindow::onIncreaseResistanceButtonClicked()
{
    int currentResistance = ui->resistanceTextEdit->toPlainText().toInt();
    if (currentResistance < 5) {
        int newResistance = currentResistance + 1;
        scadaHMI->controlResistance(newResistance);
        ui->resistanceTextEdit->setText(
            QString::number(newResistance)); // Update the resistanceTextEdit
        logActivity("Increase resistance button clicked. Resistance set to "
                    + QString::number(newResistance) + ".");
    }
}

void MainWindow::onDecreaseResistanceButtonClicked()
{
    int currentResistance = ui->resistanceTextEdit->toPlainText().toInt();
    if (currentResistance > 0) {
        int newResistance = currentResistance - 1;
        scadaHMI->controlResistance(newResistance);
        ui->resistanceTextEdit->setText(
            QString::number(newResistance)); // Update the resistanceTextEdit
        logActivity("Decrease resistance button clicked. Resistance set to "
                    + QString::number(newResistance) + ".");
    }
}

void MainWindow::onIncreaseInclineButtonClicked()
{
    int currentIncline = ui->inclineTextEdit->toPlainText().toInt();
    if (currentIncline < 5) {
        int newIncline = currentIncline + 1;
        scadaHMI->controlIncline(newIncline);
        ui->inclineTextEdit->setText(QString::number(newIncline)); // Update the inclineTextEdit
        logActivity("Increase incline button clicked. Incline set to " + QString::number(newIncline)
                    + ".");
    }
}

void MainWindow::onDecreaseInclineButtonClicked()
{
    int currentIncline = ui->inclineTextEdit->toPlainText().toInt();
    if (currentIncline > 0) {
        int newIncline = currentIncline - 1;
        scadaHMI->controlIncline(newIncline);
        ui->inclineTextEdit->setText(QString::number(newIncline)); // Update the inclineTextEdit
        logActivity("Decrease incline button clicked. Incline set to " + QString::number(newIncline)
                    + ".");
    }
}

void MainWindow::onIncreaseFanButtonClicked()
{
    int currentFanSpeed = ui->fanSpeedTextEdit->toPlainText().toInt();
    if (currentFanSpeed < 5) {
        int newFanSpeed = currentFanSpeed + 1;
        scadaHMI->controlFan(newFanSpeed);
        ui->fanSpeedTextEdit->setText(QString::number(newFanSpeed)); // Update the fan speed
        logActivity("Increase fan button clicked. Fan speed set to " + QString::number(newFanSpeed)
                    + ".");
    }
}

void MainWindow::onDecreaseFanButtonClicked()
{
    int currentFanSpeed = ui->fanSpeedTextEdit->toPlainText().toInt();
    if (currentFanSpeed > 1) {
        int newFanSpeed = currentFanSpeed - 1;
        scadaHMI->controlFan(newFanSpeed);
        ui->fanSpeedTextEdit->setText(QString::number(newFanSpeed)); // Update the fan speed
        logActivity("Decrease fan button clicked. Fan speed set to " + QString::number(newFanSpeed)
                    + ".");
    }
}

void MainWindow::onHeartRateButtonClicked()
{
    if (!heartRateTimer->isActive()) {
        heartRateTimer->start(1000); // Update every second
        ui->heartRateButton->setText("Stop Heart Rate");
        qDebug() << "Heart rate timer started.";
    } else {
        heartRateTimer->stop();
        ui->heartRateButton->setText("Show Heart Rate");
        qDebug() << "Heart rate timer stopped.";
    }
}

void MainWindow::onDistanceButtonClicked()
{
    double distance = ui->stepCountTextEdit->toPlainText().toInt() * 0.05 * ui->inclineTextEdit->toPlainText().toInt();
        // + static_cast<double>(QRandomGenerator::global()->bounded(9000))
        /// 1000.0; // Simulate distance between 1.0 and 10.0 km
    ui->distanceTextEdit->setText(
        QString::number(distance, 'f', 2)); // Display with 2 decimal places
    logActivity("Distance button clicked. Distance covered: " + QString::number(distance, 'f', 2)
                + " km.");
}


void MainWindow::updateHeartRate()
{
    int heartRate = QRandomGenerator::global()
                        ->bounded(60, 100); // Simulate heart rate between 60 and 100 BPM
    ui->heartRateTextEdit->setText(QString::number(heartRate));
    logActivity("Heart rate updated: " + QString::number(heartRate) + " BPM.");
    qDebug() << "Heart rate updated to" << heartRate;
}

void MainWindow::logActivity(const QString &activity)
{
    ui->activityLog->append(activity);
    qDebug() << activity; // Add debug output for logging activity
}

void MainWindow::showPage1()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::showPage2()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::showPage3()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onClockButtonClicked()
{
    // Implementation for clock button click
    logActivity("Clock button clicked.");
}

void MainWindow::onShowStepsButtonClicked()
{
    int CurrentStep = ui->stepCountTextEdit->toPlainText().toInt();
    // Implementation for showing steps
    int stepCount = CurrentStep+1;
            // QRandomGenerator::global()
                       // ->bounded(1000, 10000); // Simulate step count between 1000 and 10000
    ui->stepCountTextEdit->setText(QString::number(stepCount));
    logActivity("Steps button clicked. Steps: " + QString::number(stepCount));
    qDebug() << "Steps updated to" << stepCount;
    stepCount++;
}

void MainWindow::onShowCaloriesButtonClicked()
{
    // Implementation for showing calories burned
    double caloriesBurned = ui->stepCountTextEdit->toPlainText().toInt() * 0.05; //static_cast<double>(
        //QRandomGenerator::global()->bounded(50, 500)); // Simulate calories burned between 50 and 500
    ui->caloriesTextEdit->setText(QString::number(caloriesBurned));
    logActivity("Calories button clicked. Calories burned: " + QString::number(caloriesBurned));
    qDebug() << "Calories burned updated to" << caloriesBurned;
}

void MainWindow::onGenerateWorkoutButtonClicked()
{
    QString workoutPlan;

    // Example workout plan generation logic
    workoutPlan += "Warm-up: 5 minutes of light cardio\n";
    workoutPlan += "Cardio: 20 minutes of running at moderate pace\n";
    workoutPlan += "Strength: 3 sets of 15 squats\n";
    workoutPlan += "Strength: 3 sets of 15 push-ups\n";
    workoutPlan += "Cool-down: 5 minutes of stretching\n";

    // Display the workout plan in a suitable UI element, e.g., a QTextEdit
    ui->workoutPlanTextEdit->setText(workoutPlan);

    logActivity("Generated workout plan:\n" + workoutPlan);
    qDebug() << "Generated workout plan:\n" << workoutPlan;
}

void MainWindow::onShowDistanceButtonClicked()
{
    double distance = ui->stepCountTextEdit->toPlainText().toInt() * 0.05 * ui->inclineTextEdit->toPlainText().toInt();
                     // + static_cast<double>(QRandomGenerator::global()->bounded(9000))
                            /// 1000.0; // Simulate distance between 1.0 and 10.0 km
    ui->distanceTextEdit->setText(
        QString::number(distance, 'f', 2)); // Display with 2 decimal places
    logActivity("Distance button clicked. Distance covered: " + QString::number(distance, 'f', 2)
                + " km.");
}

void MainWindow::onSubmitButtonClicked()
{
    QString name = lineEditName->text();
    int age = spinBoxAge->value();
    labelDisplayName->setText("Name: " + name);
    labelDisplayAge->setText("Age: " + QString::number(age));
    logActivity("Submit button clicked. Name: " + name + ", Age: " + QString::number(age));

    // Switch to the second page
    ui->stackedWidget->setCurrentIndex(1);
}
