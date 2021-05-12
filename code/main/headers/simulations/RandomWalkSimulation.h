//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
#define DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H

#include <vector>
#include "../subjectData/Subject.h"
#include "../../src/subjectData/Grid.h"

class RandomWalkSimulation {
public:
    explicit RandomWalkSimulation(int nrOfSubjects);

    std::vector<Subject> &getSubjects();

    void iterateSimulation();

private:

    void initGrid();

    void initSubjects();

    void updateSickSubjectHealthStatus();

    void updateDiseaseSpreadBruteForce();

    void updateDiseaseSpreadSweepAndPrune();

    void updatePopulationHealthState();

    void updateDiseaseSpreadGridPartitioning();

    void addSubjectToGrid(Subject &subject);

private:
    std::vector<Subject> subjects;

public:
    int nrOfSubjects;
    int nrOfInfected;
    int nrOfDeceased;
    int nrOfImmune;
    int nrOfSusceptible;
    std::vector<Grid> grids;
};

#endif //DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
