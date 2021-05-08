//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_MATHEMATICALUTILS_H
#define DISEASE_SIMULATIONS_MATHEMATICALUTILS_H


#include "../../subjectData/Location.h"

class MathematicalUtils {
public:
    static double getUniformRandomNumber(double min, double max);

    static double calculateDistanceBetweenSubjects(Location* infectedLocation, Location* susceptibleLocation);

private:
};

#endif //DISEASE_SIMULATIONS_MATHEMATICALUTILS_H
