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

double Location::getXCoordinate() const {
    return this->xCoordinate;
}

double Location::getYCoordinate() const {
    return this->yCoordinate;
}

void Location::updateLocation() {
    this->xCoordinate = getUpdateCoordinate(this->xCoordinate, 0, ConfigUtils::getGridWidth());
    this->yCoordinate = getUpdateCoordinate(this->yCoordinate, ConfigUtils::getSirPlotHeight(),
                                            ConfigUtils::getGridHeight());
}

double
Location::getUpdateCoordinate(const double coordinate, const double minCoordinate, const double maxCoordinate) const {
    double largestStepSize = 4.5;
    double step = MathematicalUtils::getUniformRandomNumber(-largestStepSize, largestStepSize);
    if (coordinate + step >= maxCoordinate || coordinate + step <= minCoordinate) {
        return coordinate - 2 * step;
    }
    return coordinate + step;
}


