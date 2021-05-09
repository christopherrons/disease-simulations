//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_INFECTIONSPREADCALCULATOR_H
#define DISEASE_SIMULATIONS_INFECTIONSPREADCALCULATOR_H

#include "utils/MathematicalUtils.h"

class InfectionSpreadCalculator {
public:
    explicit InfectionSpreadCalculator();

    static bool isInitialInfection();

    static bool isInfectionSpread();

    static bool isRecovered(int daysSickWeight);

    static bool isDeceased();

    static bool isImmune();


private:

};


#endif //DISEASE_SIMULATIONS_INFECTIONSPREADCALCULATOR_H
