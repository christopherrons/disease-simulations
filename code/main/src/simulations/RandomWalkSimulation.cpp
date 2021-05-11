//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/simulations/RandomWalkSimulation.h"

RandomWalkSimulation::RandomWalkSimulation(int nrOfSubjects) {
    this->nrOfSubjects = nrOfSubjects;
    this->nrOfSusceptible = 0;
    this->nrOfDeceased = 0;
    this->nrOfImmune = 0;
    this->nrOfInfected = 0;

    initSubjects();
    updatePopulationHealthState();
}

void RandomWalkSimulation::initSubjects() {
    for (int i = 0; i < this->nrOfSubjects; i++) {
        this->subjects.emplace_back(Subject(i));
    }
}

std::vector<Subject> &RandomWalkSimulation::getSubjects() {
    return this->subjects;
}

void RandomWalkSimulation::iterateSimulation() {
    updateSickSubjectHealthStatus();
    updateDiseaseSpread();
    for (auto &subject: this->subjects) {
        if (!subject.getHealthStatus().isDeceased()) {
            subject.updateLocation();
        }
    }
    updatePopulationHealthState();
}

void RandomWalkSimulation::updateSickSubjectHealthStatus() {
    for (auto &subject : this->subjects) {
        subject.updateHealthStatus();
    }
}

//TODO: Cleanup
void RandomWalkSimulation::updateDiseaseSpread() {
    int infectionSpreadRadius = 45;
    for (auto &subject : this->subjects) {
        if (!subject.getHealthStatus().isDeceased() && !subject.getHealthStatus().isImmune() &&
            subject.getHealthStatus().isInfected()) {
            for (auto &susceptibleSubject : this->subjects) {
                if (!susceptibleSubject.getHealthStatus().isDeceased() &&
                    !susceptibleSubject.getHealthStatus().isImmune() &&
                    !susceptibleSubject.getHealthStatus().isInfected()) {
                    if (MathematicalUtils::calculateDistanceBetweenSubjects(
                            subject.getLocation(), susceptibleSubject.getLocation()) < infectionSpreadRadius) {
                        if (InfectionSpreadCalculator::isInfectionSpread()) {
                            susceptibleSubject.getHealthStatus().setIsInfected(true);
                        }
                    }
                }
            }
        }
    }
}

void RandomWalkSimulation::updatePopulationHealthState() {
    this->nrOfSusceptible = 0;
    this->nrOfDeceased = 0;
    this->nrOfImmune = 0;
    this->nrOfInfected = 0;
    for (auto &subject : this->subjects) {
        if (subject.getHealthStatus().isInfected()) {
            this->nrOfInfected++;
        } else if (subject.getHealthStatus().isImmune()) {
            this->nrOfImmune++;
        } else if (subject.getHealthStatus().isDeceased()) {
            this->nrOfDeceased++;
        } else {
            this->nrOfSusceptible++;
        }
    }
   // std::cout << this->nrOfInfected;
}


