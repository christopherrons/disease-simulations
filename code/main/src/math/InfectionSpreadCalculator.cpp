//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/math/InfectionSpreadCalculator.h"

InfectionSpreadCalculator::InfectionSpreadCalculator() = default;

bool InfectionSpreadCalculator::isInitialInfection() {
    int infectionRate = 5;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= infectionRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isInfectionSpread() {
    int infectionRate = 70;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= infectionRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isRecovered(int daysSickWeight) {
    double recoveryRate = 5 + daysSickWeight * 0.1;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= recoveryRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isDeceased() {
    int deathRate = 1;
    double value = MathematicalUtils::getUniformRandomNumber(0, 100);
    //std::cout << value << "\n";
    if (value <= deathRate) {
        return true;
    }
    return false;
}

bool InfectionSpreadCalculator::isImmune() {
    int immuneRate = 60;
    if (MathematicalUtils::getUniformRandomNumber(0, 100) <= immuneRate) {
        return true;
    }
    return false;
}




