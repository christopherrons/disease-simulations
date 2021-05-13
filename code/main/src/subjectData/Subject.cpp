//
// Created by christopher on 2021-05-08.
//

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../headers/subjectData/Subject.h"

Subject::Subject(int id)
        : id(id),
          location(Location()),
          healthStatus(HealthStatus()),
          subjectShape(sf::CircleShape(4)) {
}

void Subject::updateLocation() {
    this->location.updateLocation();
}

void Subject::updateHealthStatus() {
    this->healthStatus.updateHealthStatus();
}

const sf::CircleShape &Subject::getSubjectTexture() {
    this->subjectShape.setPosition(this->location.getXCoordinate(), this->location.getYCoordinate());
    if (this->healthStatus.isInfected()) {
        this->subjectShape.setFillColor(ConfigUtils::infectedColor());
    } else if (this->healthStatus.isImmune()) {
        this->subjectShape.setFillColor(ConfigUtils::immuneColor());
    } else if (this->healthStatus.isDeceased()) {
        this->subjectShape.setFillColor(ConfigUtils::deseasedColor());
        this->subjectShape.setRadius(5);
    } else {
        this->subjectShape.setFillColor(ConfigUtils::susceptibleColor());
    }
    return this->subjectShape;
}

HealthStatus &Subject::getHealthStatus() {
    return this->healthStatus;
}

Location &Subject::getLocation() {
    return this->location;
}

int Subject::getId() const {
    return this->id;
}



