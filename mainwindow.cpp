#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scadaHMI(new SCADA_HMI(this))
{
    ui->setupUi(this);
    connect(scadaHMI, &SCADA_HMI::updateUI, this, &MainWindow::updateUI);
    connect(ui->fanButton, &QPushButton::clicked, this, &MainWindow::onFanButtonClicked);
    connect(ui->increaseResistanceButton, &QPushButton::clicked, this, &MainWindow::onIncreaseResistanceButtonClicked);
    connect(ui->decreaseResistanceButton, &QPushButton::clicked, this, &MainWindow::onDecreaseResistanceButtonClicked);
    connect(ui->increaseInclineButton, &QPushButton::clicked, this, &MainWindow::onIncreaseInclineButtonClicked);
    connect(ui->decreaseResistanceButton_4, &QPushButton::clicked, this, &MainWindow::onDecreaseInclineButtonClicked);
    connect(ui->clockButton, &QPushButton::clicked, this, &MainWindow::onClockButtonClicked);
    connect(ui->increaseFanButton, &QPushButton::clicked, this, &MainWindow::onIncreaseFanButtonClicked);
    connect(ui->decreaseFanButton, &QPushButton::clicked, this, &MainWindow::onDecreaseFanButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateUI(double speed, int resistance, int incline, int heartRate, int stepCount, double caloriesBurned, double distance, QString clockMode) {
    ui->fanSpeedTextEdit->setText(QString::number(speed)); // Update the fan speed
    ui->resistanceTextEdit->setText(QString::number(resistance));
    ui->inclineTextEdit->setText(QString::number(incline));
    ui->heartRateTextEdit->setText(QString::number(heartRate));
    ui->stepCountTextEdit->setText(QString::number(stepCount));
    ui->caloriesTextEdit->setText(QString::number(caloriesBurned));
    ui->distanceTextEdit->setText(QString::number(distance));
    ui->clockModeTextEdit->setText(clockMode);
    logActivity("UI updated with new statistics.");
}

void MainWindow::onFanButtonClicked() {
    scadaHMI->controlFan(1); // Example: Set fan speed to 1
    ui->fanSpeedTextEdit->setText(QString::number(1)); // Update the fan speed
    logActivity("Fan button clicked. Fan speed set to 1.");
}

void MainWindow::onIncreaseResistanceButtonClicked() {
    int newResistance = 5; // Example: Increase resistance to 5
    scadaHMI->controlResistance(newResistance);
    ui->resistanceTextEdit->setText(QString::number(newResistance)); // Update the resistanceTextEdit
    logActivity("Increase resistance button clicked. Resistance set to " + QString::number(newResistance) + ".");
}

void MainWindow::onDecreaseResistanceButtonClicked() {
    int newResistance = 3; // Example: Decrease resistance to 3
    scadaHMI->controlResistance(newResistance);
    ui->resistanceTextEdit->setText(QString::number(newResistance)); // Update the resistanceTextEdit
    logActivity("Decrease resistance button clicked. Resistance set to " + QString::number(newResistance) + ".");
}

void MainWindow::onIncreaseInclineButtonClicked() {
    int newIncline = 5; // Example: Increase incline to 5
    scadaHMI->controlIncline(newIncline);
    ui->inclineTextEdit->setText(QString::number(newIncline)); // Update the inclineTextEdit
    logActivity("Increase incline button clicked. Incline set to " + QString::number(newIncline) + ".");
}

void MainWindow::onDecreaseInclineButtonClicked() {
    int newIncline = 3; // Example: Decrease incline to 3
    scadaHMI->controlIncline(newIncline);
    ui->inclineTextEdit->setText(QString::number(newIncline)); // Update the inclineTextEdit
    logActivity("Decrease incline button clicked. Incline set to " + QString::number(newIncline) + ".");
}

void MainWindow::onClockButtonClicked() {
    QString newClockMode = "Timer"; // Example: Set clock to Timer mode
    int countdownTime = 60; // Example: Set countdown time to 60 seconds
    scadaHMI->controlClock(newClockMode, countdownTime);
    ui->clockModeTextEdit->setText(newClockMode + " (" + QString::number(countdownTime) + "s)"); // Update the clockModeTextEdit
    logActivity("Clock button clicked. Clock set to " + newClockMode + " mode with " + QString::number(countdownTime) + " seconds countdown.");
}

void MainWindow::onIncreaseFanButtonClicked() {
    int newSpeed = 2; // Example: Increase fan speed to 2
    scadaHMI->controlFan(newSpeed);
    ui->fanSpeedTextEdit->setText(QString::number(newSpeed)); // Update the fanSpeedTextEdit
    logActivity("Increase fan button clicked. Fan speed increased to " + QString::number(newSpeed) + ".");
}

void MainWindow::onDecreaseFanButtonClicked() {
    int newSpeed = 0; // Example: Decrease fan speed to 0
    scadaHMI->controlFan(newSpeed);
    ui->fanSpeedTextEdit->setText(QString::number(newSpeed)); // Update the fanSpeedTextEdit
    logActivity("Decrease fan button clicked. Fan speed decreased to " + QString::number(newSpeed) + ".");
}

void MainWindow::logActivity(const QString &activity) {
    ui->activityLog->append(activity);
}
