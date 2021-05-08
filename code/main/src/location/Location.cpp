//
// Created by christopher on 2021-05-08.
//

#include "../../headers/location/Location.h"
#include "../../headers/utils/RandomNumberGeneratorUtils.h"

Location::Location() {
    this->xCoordinate = RandomNumberGeneratorUtils::getUniformRandomNumber(0, GridUtils::getGridWidth());
    this->yCoordinate = RandomNumberGeneratorUtils::getUniformRandomNumber(0, GridUtils::getGridHeight());
}

double Location::getXCoordinate() const {
    return this->xCoordinate;
}

double Location::getyCoordinate() const {
    return this->yCoordinate;
}

void Location::updateLocation() {
    this->xCoordinate = getUpdateCoordinate(this->xCoordinate, 0, GridUtils::getGridWidth());
    this->yCoordinate = getUpdateCoordinate(this->yCoordinate, 0, GridUtils::getGridHeight());
}

double Location::getUpdateCoordinate(double coordinate, double min, double max) const {
    double step = RandomNumberGeneratorUtils::getUniformRandomNumber(-1, 1);
    if (coordinate + step >= max || coordinate + step <= min) {
        return coordinate - 2 * step;
    }
    return coordinate + step;
}


