//
// Created by christopher on 2021-05-12.
//

#include <iostream>
#include <functional>
#include "../../headers/math/SweepPruneAlgorithm.h"

SweepPruneAlgorithm::SweepPruneAlgorithm() {}

std::vector<std::vector<Subject>> SweepPruneAlgorithm::sweepAndPrune(std::vector<Subject> &subjects) {
    sortByAxis(subjects);
    std::vector<std::vector<Subject>> activeIntervals;
    std::vector<Subject> activeInterval;
    std::cout << "Iter" << std::endl;
    for (int i = 0; i < subjects.size(); i++) {
       // std::cout <<t<< std::endl;

        if (activeInterval.empty()) {
            activeInterval.push_back(subjects[i]);
        } else if (subjects[i].getLocation().getXCoordinate() - activeInterval[activeInterval.size()-1].getLocation().getXCoordinate() < 1) {
            activeInterval.push_back(subjects[i]);
        } else {
        //    std::cout << "hello" << std::endl;

            std::vector<Subject> previousInterval = activeInterval;
            std::cout << previousInterval.size() << std::endl;
            activeIntervals.push_back(previousInterval);
            activeInterval.clear();
            activeInterval.push_back(subjects[i]);
        }
       // std::cout << subjects[i].getLocation().getXCoordinate() - activeInterval[activeInterval.size()-1].getLocation().getXCoordinate() << std::endl;
        //std::cout << activeInterval[0].getLocation().getXCoordinate() << std::endl;

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
