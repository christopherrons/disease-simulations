//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_SUBJECT_H
#define DISEASE_SIMULATIONS_SUBJECT_H

#include <SFML/Graphics.hpp>
#include "../location/Location.h"
#include "../infection/Infection.h"

class Subject {
public:
    explicit Subject(int id);

    void updateLocation();

    sf::CircleShape getSubjectTexture() const;

private:
    int id;
    bool isInfected{};
    bool isImmune{};
    Location location;
    Infection infection;
};


#endif //DISEASE_SIMULATIONS_SUBJECT_H
