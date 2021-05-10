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
    this->subjectShape = sf::CircleShape(2);
}

void Subject::updateLocation() {
    this->location.updateLocation();
}

void Subject::updateHealthStatus() {
    this->healthStatus.updateHealthStatus();
}

sf::CircleShape &Subject::getSubjectTexture() {
    this->subjectShape.setPosition(this->location.getXCoordinate(), this->location.getYCoordinate());
    if (this->healthStatus.isInfected()) {
        this->subjectShape.setFillColor(sf::Color::Red);
    } else if (this->healthStatus.isImmune()) {
        this->subjectShape.setFillColor(sf::Color::Blue);
    } else if (this->healthStatus.isDeceased()) {
        this->subjectShape.setFillColor(sf::Color::Yellow);
        this->subjectShape.setRadius(5);
    } else {
        this->subjectShape.setFillColor(sf::Color::Green);
    }
    return this->subjectShape;
}

HealthStatus &Subject::getHealthStatus() {
    return this->healthStatus;
}

Location &Subject::getLocation() {
    return this->location;
}

int Subject::getId() {
    return this->id;
}



