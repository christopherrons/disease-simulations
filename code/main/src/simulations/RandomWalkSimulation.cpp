//
// Created by christopher on 2021-05-08.
//

#include "../../headers/simulations/RandomWalkSimulation.h"

RandomWalkSimulation::RandomWalkSimulation(int nrOfSubjects) {
    this->nrOfSubjects = nrOfSubjects;
    this->subjects = initSubjects();
}

std::vector<Subject> RandomWalkSimulation::initSubjects() const {
    std::vector<Subject> initialSubjects;
    initialSubjects.reserve(this->nrOfSubjects);
    for (int i = 0; i < this->nrOfSubjects; i++) {
        initialSubjects.emplace_back(Subject(i));
    }
    return initialSubjects;
}

std::vector<Subject> RandomWalkSimulation::getSubjects() {
    return this->subjects;
}

void RandomWalkSimulation::iterateSimulation() {
    for (auto &subject: this->subjects) {
        subject.updateLocation();
    }
}
