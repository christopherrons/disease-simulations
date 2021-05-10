//
// Created by christopher on 2021-05-08.
//

#include "../../headers/subjectData/Location.h"
#include "../../headers/math/utils/MathematicalUtils.h"

Location::Location() {
    this->xCoordinate = MathematicalUtils::getUniformRandomNumber(0, ConfigUtils::getGridWidth());
    this->yCoordinate = MathematicalUtils::getUniformRandomNumber(ConfigUtils::getSirPlotHeight(),
                                                                  ConfigUtils::getGridHeight());
}

double Location::getXCoordinate() {
    return this->xCoordinate;
}

double Location::getYCoordinate() {
    return this->yCoordinate;
}

void Location::updateLocation() {
    this->xCoordinate = getUpdateCoordinate(this->xCoordinate, 0, ConfigUtils::getGridWidth());
    this->yCoordinate = getUpdateCoordinate(this->yCoordinate, ConfigUtils::getSirPlotHeight(),
                                            ConfigUtils::getGridHeight());
}

double Location::getUpdateCoordinate(double coordinate, double min, double max) {
    double step = MathematicalUtils::getUniformRandomNumber(-3.5, 3.5);
    if (coordinate + step >= max || coordinate + step <= min) {
        return coordinate - 2 * step;
    }
    return coordinate + step;
}


