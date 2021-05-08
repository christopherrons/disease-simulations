//
// Created by christopher on 2021-05-08.
//

#include "../../headers/infection/Infection.h"

Infection::Infection() {
    this->positiveInfection = false;
    initInfection();
}

void Infection::initInfection() {
    if (RandomNumberGeneratorUtils::getUniformRandomNumber(0,10) < 1) {
        this->positiveInfection = true;
    }
}

bool Infection::isInfectionPositive() const {
    return this->positiveInfection;
}