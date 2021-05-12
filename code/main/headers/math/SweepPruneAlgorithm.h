//
// Created by christopher on 2021-05-12.
//

#ifndef DISEASE_SIMULATIONS_SWEEPPRUNEALGORITHM_H
#define DISEASE_SIMULATIONS_SWEEPPRUNEALGORITHM_H


#include <vector>
#include "../subjectData/Subject.h"

class SweepPruneAlgorithm {
public:
    SweepPruneAlgorithm();
    std::vector<std::vector<Subject>>  sweepAndPrune(std::vector<Subject> &subjects);
private:
    void sortByAxis(std::vector<Subject> &subjects);
};


#endif //DISEASE_SIMULATIONS_SWEEPPRUNEALGORITHM_H
