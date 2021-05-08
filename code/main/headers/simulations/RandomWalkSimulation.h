//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
#define DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H

#include <vector>
#include "../subjects/Subject.h"

class RandomWalkSimulation {
public:
    std::vector<Subject> getSubjects();

    void iterateSimulation();

private:
    std::vector<Subject> initSubjects() const;

public:
    explicit RandomWalkSimulation(int nrOfSubjects);

private:
    int nrOfSubjects;
    std::vector<Subject> subjects;
};

#endif //DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
