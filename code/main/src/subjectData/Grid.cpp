//
// Created by christopher on 2021-05-12.
//

#include "../../headers/subjectData/Grid.h"


Grid::Grid(double xCoordinateUpperLower, double xCoordinateUpperBound, double yCoordinateUpperLower,
           double yCoordinateUpperBound)
        : xCoordinateUpperLower(xCoordinateUpperLower),
          xCoordinateUpperBound(xCoordinateUpperBound),
          yCoordinateUpperLower(yCoordinateUpperLower),
          yCoordinateUpperBound(yCoordinateUpperBound) {
}

double Grid::getXCoordinateUpperBound() const {
    return xCoordinateUpperBound;
}

double Grid::getYCoordinateUpperBound() const {
    return yCoordinateUpperBound;
}

double Grid::getXCoordinateUpperLower() const {
    return xCoordinateUpperLower;
}

double Grid::getYCoordinateUpperLower() const {
    return yCoordinateUpperLower;
}
