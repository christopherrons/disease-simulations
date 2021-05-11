//
// Created by christopher on 2021-05-08.
//

#include "../../../headers/math/utils/MathematicalUtils.h"
#include <random>
#include <iostream>

double MathematicalUtils::getUniformRandomNumber(const double min, const double max) {
    std::random_device randomDevice;
    std::default_random_engine generator(randomDevice());
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

double MathematicalUtils::calculateDistanceBetweenSubjects(const Location &infectedLocation,
                                                           const Location &susceptibleLocation) {
    double xDistance = pow(infectedLocation.getXCoordinate() - susceptibleLocation.getXCoordinate(), 2);
    double yDistance = pow(infectedLocation.getYCoordinate() - susceptibleLocation.getYCoordinate(), 2);
    return sqrt(xDistance + yDistance);
}
