//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/simulations/RandomWalkSimulation.h"
#include "../../headers/math/InfectionSpreadCalculator.h"
#include "../../headers/math/utils/MathematicalUtils.h"

RandomWalkSimulation::RandomWalkSimulation(int nrOfSubjects) {
    this->nrOfSubjects = nrOfSubjects;
    this->subjects;
    this->susceptibleSubjects;
    this->infectedSubjects;
    this->immuneSubjects;
    this->deceasedSubjects;
    this->nrOfSusceptible = 0;
    this->nrOfDeceased = 0;
    this->nrOfImmune = 0;
    this->nrOfInfected = 0;

    initSubjects();
}

void RandomWalkSimulation::initSubjects() {
    this->subjects.reserve(this->nrOfSubjects);
    for (int i = 0; i < this->nrOfSubjects; i++) {
        Subject subject = Subject(i);
        this->subjects.emplace_back(subject);
        if (subject.getHealthStatus()->isInfected()) {
            this->infectedSubjects.emplace_back(&subject);
        } else {
            this->susceptibleSubjects.emplace_back(&subject);
        }
    }
}

std::vector<Subject> RandomWalkSimulation::getSubjects() {
    return this->subjects;
}

void RandomWalkSimulation::iterateSimulation() {
    updateSickSubjectHealthStatus();
    updateDiseaseSpread();
    for (auto &subject: this->subjects) {
        if (!subject.getHealthStatus()->isDeceased()) {
            subject.updateLocation();
        }
    }
    initPopulationHealthState();
}

void RandomWalkSimulation::updateSickSubjectHealthStatus() {
    for (auto &subject : this->subjects) {
        if (subject.getHealthStatus()->isInfected()) {
            subject.updateHealthStatus();
        }
    }
}

void RandomWalkSimulation::updateDiseaseSpread() {
    int infectionSpreadZone = 450;
    for (auto &subject : this->subjects) {
        if (!subject.getHealthStatus()->isDeceased() && !subject.getHealthStatus()->isImmune() && subject.getHealthStatus()->isInfected()) {
            for (auto &susceptibleSubject : this->subjects) {
                if (!subject.getHealthStatus()->isDeceased() && !subject.getHealthStatus()->isImmune() && !subject.getHealthStatus()->isInfected()) {
                    if (MathematicalUtils::calculateDistanceBetweenSubjects(
                            subject.getLocation(), susceptibleSubject.getLocation()) < infectionSpreadZone) {

                        if (InfectionSpreadCalculator::isInfectionSpread()) {
                            // std::cout << "Infected\n";
                            susceptibleSubject.getHealthStatus()->setIsInfected(true);
                        }
                    }
                }
            }
        }
    }
}

void RandomWalkSimulation::initPopulationHealthState() {
    this->nrOfSusceptible = 0;
    this->nrOfDeceased = 0;
    this->nrOfImmune = 0;
    this->nrOfInfected = 0;
    for (auto &subject : this->subjects) {
        if (subject.getHealthStatus()->isInfected()) {
            this->nrOfInfected++;
        } else if (subject.getHealthStatus()->isImmune()) {
            this->nrOfImmune++;
        }else if (subject.getHealthStatus()->isDeceased()) {
            this->nrOfDeceased++;
        } else {
            this->nrOfSusceptible++;
        }
    }
}
/*
void RandomWalkSimulation::updateDiseaseSpread() {
    int infectionSpreadZone = 5;
    for (auto &infectedSubject : this->infectedSubjects) {
        for (auto &susceptibleSubject : this->susceptibleSubjects) {
            if (MathematicalUtils::calculateDistanceBetweenSubjects(infectedSubject.getLocation(),
                                                                    susceptibleSubject.getLocation()) <
                infectionSpreadZone) {
                if (InfectionSpreadCalculator::isInfectionSpread()) {
                    //std::cout << "Subject " << susceptibleSubject.first << " SHould be infected " << susceptibleSubject.second.getHealthStatus() << "\n";
                    //    std::cout <<  susceptibleSubject.second.getId();
                    susceptibleSubject.getHealthStatus().setIsInfected(true);
                }
            }
        }
    }*/


