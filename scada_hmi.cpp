#include "scada_hmi.h"
#include <iostream>

SCADA_HMI::SCADA_HMI(QObject *parent)
    : QObject(parent)
{}

void SCADA_HMI::displayStatistics(double speed,
                                  int resistance,
                                  int incline,
                                  int heartRate,
                                  int stepCount,
                                  double caloriesBurned,
                                  double distance,
                                  QString clockMode)
{
    emit updateUI(speed,
                  resistance,
                  incline,
                  heartRate,
                  stepCount,
                  caloriesBurned,
                  distance,
                  clockMode);
}

void SCADA_HMI::controlFan(int speedLevel)
{
    // Implementation for controlling fan speed
    std::cout << "Fan Speed Level: " << speedLevel << "\n";
}

void SCADA_HMI::controlResistance(int level)
{
    // Implementation for controlling resistance
    std::cout << "Resistance Level: " << level << "\n";
}

void SCADA_HMI::controlIncline(int level)
{
    // Implementation for controlling incline
    std::cout << "Incline Level: " << level << "\n";
}

void SCADA_HMI::controlClock(QString mode, int countdownTime)
{
    // Implementation for controlling clock
    std::cout << "Clock Mode: " << mode.toStdString() << "\n";
    if (mode == "Timer") {
        std::cout << "Countdown Time: " << countdownTime << " seconds\n";
    }
}

void SCADA_HMI::onSpeedUpdated(double speed)
{
    displayStatistics(speed, 0, 0, 0, 0, 0, 0, "");
}

void SCADA_HMI::onResistanceUpdated(int resistance)
{
    displayStatistics(0, resistance, 0, 0, 0, 0, 0, "");
}

void SCADA_HMI::onInclineUpdated(int incline)
{
    displayStatistics(0, 0, incline, 0, 0, 0, 0, "");
}

void SCADA_HMI::onHeartRateUpdated(int heartRate)
{
    displayStatistics(0, 0, 0, heartRate, 0, 0, 0, "");
}

void SCADA_HMI::onStepCountUpdated(int stepCount)
{
    displayStatistics(0, 0, 0, 0, stepCount, 0, 0, "");
}

void SCADA_HMI::onCaloriesBurnedUpdated(double caloriesBurned)
{
    displayStatistics(0, 0, 0, 0, 0, caloriesBurned, 0, "");
}

void SCADA_HMI::onDistanceUpdated(double distance)
{
    displayStatistics(0, 0, 0, 0, 0, 0, distance, "");
}

void SCADA_HMI::onClockModeUpdated(QString clockMode)
{
    displayStatistics(0, 0, 0, 0, 0, 0, 0, clockMode);
}
