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

    void updateSubjectLocation();

    void initPopulationHealthState();

private:
    std::vector<Subject> subjects;
    std::vector<Subject *> susceptibleSubjects;
    std::vector<Subject *> infectedSubjects;
    std::vector<Subject *> immuneSubjects;
    std::vector<Subject *> deceasedSubjects;

public:
    int nrOfSubjects;
    int nrOfInfected;
    int nrOfDeceased;
    int nrOfImmune;
    int nrOfSusceptible;
};

#endif //DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
