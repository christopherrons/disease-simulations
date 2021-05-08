//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_INFECTION_H
#define DISEASE_SIMULATIONS_INFECTION_H

#include "../utils/RandomNumberGeneratorUtils.h"

class Infection {
public:
    explicit Infection();

    void initInfection();

    bool isInfectionPositive() const;

private:
    bool positiveInfection;
};


#endif //DISEASE_SIMULATIONS_INFECTION_H
