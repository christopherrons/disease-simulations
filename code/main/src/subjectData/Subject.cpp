//
// Created by christopher on 2021-05-08.
//

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../headers/subjectData/Subject.h"

Subject::Subject(int id) {
    this->id = id;
    this->location = Location();
    this->healthStatus = HealthStatus();
}

void Subject::updateLocation() {
    this->location.updateLocation();
}

void Subject::updateHealthStatus() {
    this->healthStatus.updateHealthStatus();
}

sf::CircleShape Subject::getSubjectTexture() {
    sf::CircleShape shape(2);
    shape.setPosition(this->location.getXCoordinate(), this->location.getYCoordinate());
    if (this->healthStatus.isInfected()) {
        shape.setFillColor(sf::Color::Red);
    } else if (this->healthStatus.isImmune()) {
        shape.setFillColor(sf::Color::Blue);
    } else if (this->healthStatus.isDeceased()) {
        shape.setFillColor(sf::Color::Yellow);
        shape.setRadius(5);
    } else {
        shape.setFillColor(sf::Color::Green);
    }
    return shape;
}

HealthStatus *Subject::getHealthStatus() {
    return &this->healthStatus;
}

Location *Subject::getLocation() {
    return &this->location;
}

int *Subject::getId() {
    return &this->id;
}



