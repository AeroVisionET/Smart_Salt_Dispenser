#ifndef SALTER3000_H
#define SALTER3000_H

#include <memory>
#include <iostream>

class SaltDispenser {
private:
    float dispenseRate;      // Grams per second
    float saltLeft;          // Amount of salt left in grams
    bool foodDetected;       // Food detection state (true/false)
    bool actuatorState;      // Actuator state (true for dispensing, false otherwise)

public:
    SaltDispenser();
    ~SaltDispenser();

    // Setters
    void setDispenseRate(float rate);
    void setSaltLeft(float amount);
    void setFoodDetected(bool detected);

    // Getters
    float getDispenseRate() const;
    float getSaltLeft() const;
    bool isFoodDetected() const;
    bool isActuatorOn() const;

    // Core methods
    void controlDispensing();
    void stopDispensing();
};

#endif // SALTER3000_H
