//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
#define DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H

#include <vector>
#include "../subjectData/Subject.h"

class RandomWalkSimulation {
public:
    explicit RandomWalkSimulation(int nrOfSubjects);

    std::vector<Subject> &getSubjects();

    void iterateSimulation();

private:
    void initSubjects();

    void updateSickSubjectHealthStatus();

    void updateDiseaseSpread();

    void updatePopulationHealthState();

private:
    std::vector<Subject> subjects;

public:
    int nrOfSubjects;
    int nrOfInfected;
    int nrOfDeceased;
    int nrOfImmune;
    int nrOfSusceptible;
};

#endif //DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
