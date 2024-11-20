#include "salter3000.h"

// Constructor
SaltDispenser::SaltDispenser()
    : dispenseRate(0.0f), saltLeft(0.0f), foodDetected(false), actuatorState(false) {}

// Destructor
SaltDispenser::~SaltDispenser() {
    std::cout << "SaltDispenser destroyed.\n";
}

// Setters
void SaltDispenser::setDispenseRate(float rate) {
    if (rate >= 0.0f) {
        dispenseRate = rate;
    } else {
        std::cerr << "Error: Dispense rate must be non-negative.\n";
    }
}

void SaltDispenser::setSaltLeft(float amount) {
    if (amount >= 0.0f) {
        saltLeft = amount;
    } else {
        std::cerr << "Error: Salt left must be non-negative.\n";
    }
}

void SaltDispenser::setFoodDetected(bool detected) {
    foodDetected = detected;
}

// Getters
float SaltDispenser::getDispenseRate() const {
    return dispenseRate;
}

float SaltDispenser::getSaltLeft() const {
    return saltLeft;
}

bool SaltDispenser::isFoodDetected() const {
    return foodDetected;
}

bool SaltDispenser::isActuatorOn() const {
    return actuatorState;
}

// Core methods
void SaltDispenser::controlDispensing() {
    if (foodDetected && saltLeft > 0.0f && dispenseRate > 0.0f) {
        actuatorState = true;
        saltLeft -= dispenseRate; // Reduce salt based on dispense rate
        std::cout << "Dispensing salt: " << dispenseRate << " g/s. Salt left: " << saltLeft << " g.\n";
    } else if (saltLeft <= 0.0f) {
        stopDispensing();
        std::cerr << "Error: Salt has run out!\n";
    } else {
        stopDispensing();
    }
}

void SaltDispenser::stopDispensing() {
    actuatorState = false;
    std::cout << "Stopped dispensing salt.\n";
}
