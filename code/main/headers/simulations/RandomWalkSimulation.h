//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
#define DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H

#include <vector>
#include "../subjectData/Subject.h"

class RandomWalkSimulation {
public:
    std::vector<Subject> getSubjects();

    void iterateSimulation();

private:
    void initSubjects();

    void updateSickSubjectHealthStatus();

    void updateDiseaseSpread();

    void updateSubjectLocation();

public:
    explicit RandomWalkSimulation(int nrOfSubjects);

private:
    int nrOfSubjects;
    std::vector<Subject> subjects;
    std::vector<Subject *> susceptibleSubjects;
    std::vector<Subject *> infectedSubjects;
    std::vector<Subject *> immuneSubjects;
    std::vector<Subject *> deceasedSubjects;
};

#endif //DISEASE_SIMULATIONS_RANDOMWALKSIMULATION_H
