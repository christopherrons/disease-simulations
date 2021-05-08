//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_HEALTHSTATUS_H
#define DISEASE_SIMULATIONS_HEALTHSTATUS_H

#include "../../headers/math/InfectionSpreadCalculator.h"

class HealthStatus {
public:
    HealthStatus();

    bool isInfected();

    void setIsInfected(bool infected);

    bool isImmune();

    void setIsImmune(bool immune);

    bool isDeceased();

    void setIsDeceased(bool deceased);

    bool isNrOfDaysSick();

    void setNrOfDaysSick(int currentNrOfDaysSick);

    void updateHealthStatus();

private:
    bool infected;
    bool immune;
    bool deceased;
    int nrOfDaysSick;

};


#endif //DISEASE_SIMULATIONS_HEALTHSTATUS_H
