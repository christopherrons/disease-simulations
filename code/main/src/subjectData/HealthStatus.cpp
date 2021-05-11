//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/subjectData/HealthStatus.h"


HealthStatus::HealthStatus() {
    this->infected = InfectionSpreadCalculator::isInitialInfection();
    this->immune = false;
    this->deceased = false;
    this->nrOfDaysSick = 0;
}

void HealthStatus::updateHealthStatus() {
    if (this->isInfected() && !this->isDeceased()) {
        if (InfectionSpreadCalculator::isRecovered(this->nrOfDaysSick + 1)) {
            this->infected = false;
            this->nrOfDaysSick = 0;
            if (InfectionSpreadCalculator::isImmune()) {
                this->immune = true;
            }
        } else if (InfectionSpreadCalculator::isDeceased()) {
            this->infected = false;
            this->deceased = true;
        }
    }
}

bool HealthStatus::isInfected() const {
    return this->infected;
}

void HealthStatus::setIsInfected(const bool isInfected) {
    this->infected = isInfected;
}

bool HealthStatus::isImmune() const {
    return this->immune;
}

void HealthStatus::setIsImmune(const bool isImmune) {
    this->immune = isImmune;
}

bool HealthStatus::isDeceased() const {
    return this->deceased;
}

void HealthStatus::setIsDeceased(bool isDeceased) {
    this->deceased = isDeceased;
}

bool HealthStatus::isNrOfDaysSick() const {
    return nrOfDaysSick;
}

void HealthStatus::setNrOfDaysSick(const int currentNrOfDaysSick) {
    this->nrOfDaysSick = currentNrOfDaysSick;
}




