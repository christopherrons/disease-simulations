//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/math/InfectionSpreadCalculator.h"

InfectionSpreadCalculator::InfectionSpreadCalculator() = default;

bool InfectionSpreadCalculator::isInitialInfection() {
    const int infectionRate = 5;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= infectionRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isInfectionSpread() {
    const int infectionRate = 70;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= infectionRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isRecovered(int daysSickWeight) {
    const double recoveryRate = 5 + daysSickWeight * 0.1;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= recoveryRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isDeceased() {
    const int deathRate = 1;
    double value = MathematicalUtils::getUniformRandomNumber(0, 100);
    //std::cout << value << "\n";
    if (value <= deathRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isImmune() {
    const int immuneRate = 20;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= immuneRate) {
        return true;
    }
    return false;
}




