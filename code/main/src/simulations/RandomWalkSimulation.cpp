//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/simulations/RandomWalkSimulation.h"
#include "../../headers/math/SweepPruneAlgorithm.h"

RandomWalkSimulation::RandomWalkSimulation(int nrOfSubjects) {
    this->nrOfSubjects = nrOfSubjects;
    this->nrOfSusceptible = 0;
    this->nrOfDeceased = 0;
    this->nrOfImmune = 0;
    this->nrOfInfected = 0;

    initGrid();
    initSubjects();
    updatePopulationHealthState();
}

void RandomWalkSimulation::initGrid() {
    for (int i = 1; i < ConfigUtils::nrOfGrids() + 1; i++) {
        this->grids.emplace_back(ConfigUtils::getGridWidth() * (i - 1) / ConfigUtils::nrOfGrids(),
                                 ConfigUtils::getGridWidth() * (i / ConfigUtils::nrOfGrids()),
                                 ConfigUtils::getGridHeight() * (i - 1) / ConfigUtils::nrOfGrids(),
                                 ConfigUtils::getGridHeight() * (i / ConfigUtils::nrOfGrids()));
    }
}

void RandomWalkSimulation::initSubjects() {
    for (int i = 0; i < this->nrOfSubjects; i++) {
        Subject subject = Subject(i);
        this->subjects.push_back(subject);
        addSubjectToGrid(subject);
    }
}

void RandomWalkSimulation::addSubjectToGrid(Subject &subject) {
  //  std::cout << "Grids" << std::endl;
    for (auto &grid: this->grids) {
        ///   std::cout << "XLow" << grid.getXCoordinateUpperLower() << std::endl;
        //  std::cout << "XHigh" << grid.getXCoordinateUpperBound() << std::endl;
        //  std::cout << "YLow" << grid.getYCoordinateUpperLower() << std::endl;
        // std::cout << "YHigh" <<  grid.getYCoordinateUpperBound()<< std::endl;

       // std::cout << "" << std::endl;

        if (subject.getLocation().getXCoordinate() >= grid.getXCoordinateUpperLower() &&
            subject.getLocation().getXCoordinate() <= grid.getXCoordinateUpperBound() &&
            subject.getLocation().getYCoordinate() >= grid.getYCoordinateUpperLower() &&
            subject.getLocation().getYCoordinate() <= grid.getYCoordinateUpperBound()) {
            grid.subjectsInGrid.push_back(subject);
        }
    }
}


std::vector<Subject> &RandomWalkSimulation::getSubjects() {
    return this->subjects;
}

void RandomWalkSimulation::iterateSimulation() {
    updateSickSubjectHealthStatus();
    updateDiseaseSpreadSweepAndPrune();
    for (auto &subject: this->subjects) {
        if (!subject.getHealthStatus().isDeceased()) {
            subject.updateLocation();
        }
        addSubjectToGrid(subject);
    }
    updatePopulationHealthState();
}

void RandomWalkSimulation::updateSickSubjectHealthStatus() {
    for (auto &subject : this->subjects) {
        subject.updateHealthStatus();
    }
}

//TODO: Cleanup
void RandomWalkSimulation::updateDiseaseSpreadBruteForce() {
    int infectionSpreadRadius = 25;
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

//TODO: Cleanup
void RandomWalkSimulation::updateDiseaseSpreadSweepAndPrune() {
    SweepPruneAlgorithm sweepPruneAlgorithm;
    std::vector<Subject> updatedSubjects;
    std::cout << "\nNew teration" << std::endl;
    for (auto &subjectsInSpreadRadius : sweepPruneAlgorithm.sweepAndPrune(this->subjects)) {
        std::cout << "Sizer: " << subjectsInSpreadRadius.size() << std::endl;
        for (auto &subjectInSpreadRadius: subjectsInSpreadRadius) {
            updatedSubjects.emplace_back(subjectInSpreadRadius);
            if (subjectInSpreadRadius.getHealthStatus().isInfected()) {
                for (auto &susceptibleSubject : subjectsInSpreadRadius) {
                    if (susceptibleSubject.getHealthStatus().isSusceptible()) {
                        if (MathematicalUtils::calculateDistanceBetweenSubjects(
                                susceptibleSubject.getLocation(), susceptibleSubject.getLocation()) <
                            InfectionSpreadCalculator::getInfectionSpreadRadius()) {
                            if (InfectionSpreadCalculator::isInfectionSpread()) {
                                susceptibleSubject.getHealthStatus().setIsInfected(true);
                            }
                        }
                    }
                }
            }
        }
    }
    subjects = updatedSubjects;
}

//TODO: Cleanup
void RandomWalkSimulation::updateDiseaseSpreadGridPartitioning() {
    std::vector<Subject> updatedSubjects;
    std::cout << "\nNew teration" << std::endl;
    for (auto &grid: this->grids) {
        std::cout << grid.subjectsInGrid.size() << std::endl;
        for (auto &subjectInSpreadRadius: grid.subjectsInGrid) {
            updatedSubjects.push_back(subjectInSpreadRadius);
            if (subjectInSpreadRadius.getHealthStatus().isInfected()) {
                for (auto &susceptibleSubject: grid.subjectsInGrid) {
                    if (susceptibleSubject.getHealthStatus().isSusceptible()) {
                        if (MathematicalUtils::calculateDistanceBetweenSubjects(
                                susceptibleSubject.getLocation(), susceptibleSubject.getLocation()) <
                            InfectionSpreadCalculator::getInfectionSpreadRadius()) {
                            if (InfectionSpreadCalculator::isInfectionSpread()) {
                                susceptibleSubject.getHealthStatus().setIsInfected(true);
                            }
                        }
                    }
                }
            }
        }
        grid.subjectsInGrid.clear();
    }
    subjects = updatedSubjects;
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
}





