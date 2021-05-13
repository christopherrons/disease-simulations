//
// Created by christopher on 2021-05-08.
//

#include <iostream>
#include "../../headers/simulations/RandomWalkSimulation.h"
#include "../../headers/math/SweepPruneAlgorithm.h"

RandomWalkSimulation::RandomWalkSimulation(int nrOfSubjects)
        : nrOfSubjects(nrOfSubjects),
          nrOfSusceptible(0),
          nrOfDeceased(0),
          nrOfImmune(0),
          nrOfInfected(0) {

    initGrid();
    initSubjects();
    addSubjectsToGrids();
    updatePopulationHealthState();
}

void RandomWalkSimulation::initGrid() {
    double nrGridsPerRow = ConfigUtils::nrOfGridsPerRow();
    for (int y = 1; y < nrGridsPerRow + 1; y++) {
        for (int x = 1; x < nrGridsPerRow + 1; x++) {
            this->grids.emplace_back(ConfigUtils::getGridWidth() * (x - 1) / nrGridsPerRow,
                                     ConfigUtils::getGridWidth() * (x / nrGridsPerRow),
                                     ConfigUtils::getGridHeight() * (y - 1) / nrGridsPerRow,
                                     ConfigUtils::getGridHeight() * (y / nrGridsPerRow));
        }
    }
}

void RandomWalkSimulation::initSubjects() {
    for (int i = 0; i < this->nrOfSubjects; i++) {
        Subject subject = Subject(i);
        this->subjects.push_back(subject);
    }
}

void RandomWalkSimulation::addSubjectsToGrids() {
    for (auto &subject: this->subjects) {
        for (auto &grid: this->grids) {
            if (subject.getLocation().getXCoordinate() >= grid.getXCoordinateUpperLower() &&
                subject.getLocation().getXCoordinate() <= grid.getXCoordinateUpperBound() &&
                subject.getLocation().getYCoordinate() >= grid.getYCoordinateUpperLower() &&
                subject.getLocation().getYCoordinate() <= grid.getYCoordinateUpperBound()) {
                grid.subjectsInGrid.push_back(subject);
            }
        }
    }
    this->subjects.clear();
}

std::vector<Subject> &RandomWalkSimulation::getSubjects() {
    for (auto &grid: this->grids) {
        for (auto &subject: grid.subjectsInGrid) {
            this->subjects.push_back(subject);
        }
        grid.subjectsInGrid.clear();
    }
    return this->subjects;
}

void RandomWalkSimulation::iterateSimulation() {
    addSubjectsToGrids();
    updateSickSubjectHealthStatus();
    updateDiseaseSpreadGridPartitioning();
    /* for (auto &subject: this->subjects) {
         if (!subject.getHealthStatus().isDeceased()) {
             subject.updateLocation();
         }
     }*/
    for (auto &grid: this->grids) {
        for (auto &subject: grid.subjectsInGrid) {
            if (!subject.getHealthStatus().isDeceased()) {
                subject.updateLocation();
            }
        }
    }
    updatePopulationHealthState();
}

void RandomWalkSimulation::updateSickSubjectHealthStatus() {
    for (auto &grid: this->grids) {
        for (auto &subject: grid.subjectsInGrid) {
            subject.updateHealthStatus();
        }
    }
    /*for (auto &subject : this->subjects) {
        subject.updateHealthStatus();
    }*/
}

void RandomWalkSimulation::updateDiseaseSpreadBruteForce() {
    for (auto &subject : this->subjects) {
        if (subject.getHealthStatus().isInfected()) {
            for (auto &susceptibleSubject : this->subjects) {
                if (susceptibleSubject.getHealthStatus().isSusceptible()) {
                    if (MathematicalUtils::calculateDistanceBetweenSubjects(
                            subject.getLocation(), susceptibleSubject.getLocation()) <
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

//TODO: Cleanup and finish
void RandomWalkSimulation::updateDiseaseSpreadSweepAndPrune() {
    std::vector<Subject> updatedSubjects;
    for (auto &subjectsInSpreadRadius : SweepPruneAlgorithm::sweepAndPrune(this->subjects)) {
        for (auto &subjectInSpreadRadius: subjectsInSpreadRadius) {
            updatedSubjects.emplace_back(subjectInSpreadRadius);
            if (subjectInSpreadRadius.getHealthStatus().isInfected()) {
                for (auto &susceptibleSubject : subjectsInSpreadRadius) {
                    if (susceptibleSubject.getHealthStatus().isSusceptible()) {
                        if (MathematicalUtils::calculateDistanceBetweenSubjects(
                                subjectInSpreadRadius.getLocation(), susceptibleSubject.getLocation()) <
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

//TODO: Fix so subjects on the opposite end of a grid line are also compared
void RandomWalkSimulation::updateDiseaseSpreadGridPartitioning() {
    std::vector<Subject> updatedSubjects;
    for (auto &grid: this->grids) {
        for (auto &subjectInSpreadRadius: grid.subjectsInGrid) {
            updatedSubjects.push_back(subjectInSpreadRadius);
            if (subjectInSpreadRadius.getHealthStatus().isInfected()) {
                for (auto &susceptibleSubject: grid.subjectsInGrid) {
                    if (susceptibleSubject.getHealthStatus().isSusceptible()) {
                        if (MathematicalUtils::calculateDistanceBetweenSubjects(
                                subjectInSpreadRadius.getLocation(), susceptibleSubject.getLocation()) <
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
}

void RandomWalkSimulation::updatePopulationHealthState() {
    this->nrOfSusceptible = 0;
    this->nrOfDeceased = 0;
    this->nrOfImmune = 0;
    this->nrOfInfected = 0;
    for (auto &grid: this->grids) {
        for (auto &subject: grid.subjectsInGrid) {
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
}





