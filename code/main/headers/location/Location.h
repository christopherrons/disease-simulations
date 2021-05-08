//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_LOCATION_H
#define DISEASE_SIMULATIONS_LOCATION_H


#include "../utils/RandomNumberGeneratorUtils.h"
#include "../utils/GridUtils.h"

class Location {
public:
    explicit Location();

    void setXCoordinate(double xCoordinate);

    void setYCoordinate(double yCoordinate);

    double getXCoordinate() const;

    double getyCoordinate() const;

    void updateLocation();

private:
    double getUpdateCoordinate(double coordinate, double min, double max) const;

private:
    double xCoordinate;
    double yCoordinate;
};


#endif //DISEASE_SIMULATIONS_LOCATION_H
