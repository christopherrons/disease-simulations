//
// Created by christopher on 2021-05-08.
//

#include <cstdlib>
#include <SFML/Graphics/CircleShape.hpp>
#include "../../headers/subjects/Subject.h"

Subject::Subject(int id) {
    this->id = id;
    this->location = Location();
    this->infection = Infection();
}

void Subject::updateLocation() {
    this->location.updateLocation();
}

sf::CircleShape Subject::getSubjectTexture() const {
    sf::CircleShape shape(1.5);
    shape.setPosition(this->location.getXCoordinate(), this->location.getyCoordinate());
    if (this->infection.isInfectionPositive()) {
        shape.setFillColor(sf::Color::Red);
    } else {
        shape.setFillColor(sf::Color::Green);
    }
    return shape;
}

