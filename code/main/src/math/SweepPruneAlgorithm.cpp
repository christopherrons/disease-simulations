//
// Created by christopher on 2021-05-12.
//

#include <iostream>
#include <functional>
#include "../../headers/math/SweepPruneAlgorithm.h"



std::vector<std::vector<Subject>> SweepPruneAlgorithm::sweepAndPrune(std::vector<Subject> &subjects) {
    sortByAxis(subjects);
    std::vector<std::vector<Subject>> activeIntervals;
    std::vector<Subject> activeInterval;
    for (int i = 0; i < subjects.size(); i++) {
        if (activeInterval.empty()) {
            activeInterval.push_back(subjects[i]);
        } else if (subjects[i].getLocation().getXCoordinate() - activeInterval[activeInterval.size()-1].getLocation().getXCoordinate() < 5) {
            activeInterval.push_back(subjects[i]);
        } else {
            std::vector<Subject> previousInterval = activeInterval;
            activeIntervals.push_back(previousInterval);
            activeInterval.clear();
            activeInterval.push_back(subjects[i]);
        }

        if (i == subjects.size() - 1) {
            activeIntervals.push_back(activeInterval);
        }
    }
    if (activeIntervals.empty()) {
        activeIntervals.push_back(activeInterval);
    }
    return activeIntervals;
}

void SweepPruneAlgorithm::sortByAxis(std::vector<Subject> &subjects) {
    sort(subjects.begin(), subjects.end(), [](Subject &subjectOne, Subject &subjectTwo) {
        return subjectOne.getLocation().getXCoordinate() < subjectTwo.getLocation().getXCoordinate();
    });
}
