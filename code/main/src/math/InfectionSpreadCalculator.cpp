//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/math/InfectionSpreadCalculator.h"

InfectionSpreadCalculator::InfectionSpreadCalculator() = default;

bool InfectionSpreadCalculator::isInfectionSpread() {
    int infectionRate = 20;
    if (MathematicalUtils::getUniformRandomNumber(0,100) <= infectionRate) {
        return true;
    } return false;
}

bool InfectionSpreadCalculator::isRecovered(int daysSickWeight) {
    int recoveryRate = 5 + daysSickWeight * 2;
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




