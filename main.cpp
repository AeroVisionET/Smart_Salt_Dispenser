#include "salter3000.h"
#include <memory>

int main() {
    // Using a smart pointer to manage the SaltDispenser object
    std::unique_ptr<SaltDispenser> dispenser = std::make_unique<SaltDispenser>();

    // Setting initial parameters
    dispenser->setSaltLeft(50.0f);      // 50 grams of salt
    dispenser->setDispenseRate(5.0f);  // 5 grams/second

    // Simulating food detection
    dispenser->setFoodDetected(true);
    dispenser->controlDispensing(); // Start dispensing

    // Simulating food removed
    dispenser->setFoodDetected(false);
    dispenser->controlDispensing(); // Should stop dispensing

    // Simulating running out of salt
    dispenser->setSaltLeft(0.0f);
    dispenser->setFoodDetected(true);
    dispenser->controlDispensing(); // Error: Salt has run out

    return 0;
}
