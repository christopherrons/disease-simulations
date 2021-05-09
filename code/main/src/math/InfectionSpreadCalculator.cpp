//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/math/InfectionSpreadCalculator.h"

InfectionSpreadCalculator::InfectionSpreadCalculator() = default;

bool InfectionSpreadCalculator::isInitialInfection() {
    int infectionRate = 35;
    if (MathematicalUtils::getUniformRandomNumber(0,100) <= infectionRate) {
        return true;
    } return false;
}

bool InfectionSpreadCalculator::isInfectionSpread() {
    int infectionRate = 90;
    if (MathematicalUtils::getUniformRandomNumber(0,100) <= infectionRate) {
        return true;
    } return false;
}

bool InfectionSpreadCalculator::isRecovered(int daysSickWeight) {
    int recoveryRate = 1 + daysSickWeight * 0.1;
    if (MathematicalUtils::getUniformRandomNumber(0,100) <= recoveryRate) {
        return true;
    } return false;
}

bool InfectionSpreadCalculator::isDeceased() {
    int deathRate = 2;
    if (MathematicalUtils::getUniformRandomNumber(0,100) <= deathRate) {
        return true;
    } return false;
}

bool InfectionSpreadCalculator::isImmune() {
    int immuneRate = 90;
    if (MathematicalUtils::getUniformRandomNumber(0,100) <= immuneRate) {
        return true;
    } return false;
}




