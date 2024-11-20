#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scada_hmi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SCADA_HMI *scadaHMI;

private slots:
    void updateUI(double speed, int resistance, int incline, int heartRate, int stepCount, double caloriesBurned, double distance, QString clockMode);
    void onFanButtonClicked();
    void onIncreaseResistanceButtonClicked();
    void onDecreaseResistanceButtonClicked();
    void onIncreaseInclineButtonClicked();
    void onDecreaseInclineButtonClicked();
    void onClockButtonClicked();
    void onIncreaseFanButtonClicked();
    void onDecreaseFanButtonClicked();
    void logActivity(const QString &activity);
};

#endif // MAINWINDOW_H
