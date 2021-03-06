//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_HEALTHSTATUS_H
#define DISEASE_SIMULATIONS_HEALTHSTATUS_H

#include "../../headers/math/InfectionSpreadCalculator.h"

class HealthStatus {
public:
    HealthStatus();

    bool isInfected() const;

    void setIsInfected(bool infected);

    bool isImmune() const;

    void setIsImmune(bool immune);

    bool isDeceased() const;

    void setIsDeceased(bool deceased);

    bool isNrOfDaysSick() const;

    void setNrOfDaysSick(int currentNrOfDaysSick);

    void updateHealthStatus();

    bool isSusceptible();

private:
    bool infected;
    bool immune;
    bool deceased;
    int nrOfDaysSick;
};


#endif //DISEASE_SIMULATIONS_HEALTHSTATUS_H
