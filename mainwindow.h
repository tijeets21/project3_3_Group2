#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QTimer>
#include "scada_hmi.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SCADA_HMI *scadaHMI;
    QTimer *heartRateTimer;
    QTimer *clockTimer;
    QLineEdit *lineEditName;
    QSpinBox *spinBoxAge;
    QLabel *labelDisplayName;
    QLabel *labelDisplayAge;
    QPushButton *buttonSubmit;
    QPushButton *buttonToPage2;
    QPushButton *buttonToPage3;
    int countdownTime; // Add this line

private slots:
    void updateUI(double speed,
                  int resistance,
                  int incline,
                  int heartRate,
                  int stepCount,
                  double caloriesBurned,
                  double distance,
                  QString clockMode);
    void onFanButtonClicked();
    void onShowStepsButtonClicked();
    void onShowCaloriesButtonClicked();
    void onIncreaseResistanceButtonClicked();
    void onDecreaseResistanceButtonClicked();
    void onIncreaseInclineButtonClicked();
    void onDecreaseInclineButtonClicked();
    void onClockButtonClicked();
    void onIncreaseFanButtonClicked();
    void onDecreaseFanButtonClicked();
    void onHeartRateButtonClicked();
    void onDistanceButtonClicked();
    void updateHeartRate();
    void logActivity(const QString &activity);
    void onSubmitButtonClicked();
    void showPage1();
    void showPage2();
    void showPage3();
    void startClockTimer();
    void stopClockTimer();
    void updateClock();
    void onGenerateWorkoutButtonClicked();
    void onShowDistanceButtonClicked();
    void setCountdownTime(int time); // Add this line
};

#endif // MAINWINDOW_H
