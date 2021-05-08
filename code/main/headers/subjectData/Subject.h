//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_SUBJECT_H
#define DISEASE_SIMULATIONS_SUBJECT_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Location.h"
#include "../math/InfectionSpreadCalculator.h"
#include "HealthStatus.h"


class Subject {
public:
    Subject(int id);

    void updateLocation();

    void updateHealthStatus();

    sf::CircleShape getSubjectTexture();

    HealthStatus* getHealthStatus();

    Location* getLocation();
    int* getId();

private:
    int id;
    Location location;
    HealthStatus healthStatus;
};


#endif //DISEASE_SIMULATIONS_SUBJECT_H
