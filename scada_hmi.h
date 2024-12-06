#ifndef SCADA_HMI_H
#define SCADA_HMI_H

#include <QObject>
#include <QString>

class SCADA_HMI : public QObject
{
    Q_OBJECT
public:
    explicit SCADA_HMI(QObject *parent = nullptr);
    void displayStatistics(double speed,
                           int resistance,
                           int incline,
                           int heartRate,
                           int stepCount,
                           double caloriesBurned,
                           double distance,
                           QString clockMode);
    void controlFan(int speedLevel);                        // Existing method
    void controlResistance(int level);                      // Existing method
    void controlIncline(int level);                         // Existing method
    void controlClock(QString mode, int countdownTime = 0); // Add this line

signals:
    void updateUI(double speed,
                  int resistance,
                  int incline,
                  int heartRate,
                  int stepCount,
                  double caloriesBurned,
                  double distance,
                  QString clockMode);

public slots:
    void onSpeedUpdated(double speed);
    void onResistanceUpdated(int resistance);
    void onInclineUpdated(int incline);
    void onHeartRateUpdated(int heartRate);
    void onStepCountUpdated(int stepCount);
    void onCaloriesBurnedUpdated(double caloriesBurned);
    void onDistanceUpdated(double distance);
    void onClockModeUpdated(QString clockMode);
};

#endif // SCADA_HMI_H
