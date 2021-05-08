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
    std::cout << "Subjects created";
}

std::vector<Subject> RandomWalkSimulation::getSubjects() {
    return this->subjects;
}

void RandomWalkSimulation::iterateSimulation() {
    std::cout << "Iterate\n";
    updateSickSubjectHealthStatus();
    updateDiseaseSpread();
    for (auto &subject: this->subjects) {
        std::cout << "Subject: " << &subject << "\n";
        if (!subject.getHealthStatus()->isDeceased()) {
            subject.updateLocation();
        }
    }
    std::cout << "Done Iterate\n";
}

void RandomWalkSimulation::updateSickSubjectHealthStatus() {
    std::cout << "Updating Health\n";
    for (auto &subject : this->subjects) {
        if (subject.getHealthStatus()->isInfected()) {
            //    std::cout << "Subject: " << subject << "\n";
            subject.updateHealthStatus();
        }
    }
}

void RandomWalkSimulation::updateDiseaseSpread() {
    std::cout << "Spreading";
    int infectionSpreadZone = 150;
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


