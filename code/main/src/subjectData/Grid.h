//
// Created by christopher on 2021-05-12.
//

#ifndef DISEASE_SIMULATIONS_GRID_H
#define DISEASE_SIMULATIONS_GRID_H


#include "../../headers/subjectData/Subject.h"

class Grid {
public:
    Grid(double xCoordinateUpperLower, double xCoordinateUpperBound, double yCoordinateUpperLower,
         double yCoordinateUpperBound);

    void addToGrid(const Subject &subject);

    std::vector<Subject> subjectsInGrid;

private:
    double xCoordinateUpperBound;
    double yCoordinateUpperBound;
public:
    double getXCoordinateUpperBound() const;

    double getYCoordinateUpperBound() const;

    double getXCoordinateUpperLower() const;

    double getYCoordinateUpperLower() const;

private:
    double xCoordinateUpperLower;
    double yCoordinateUpperLower;
};


#endif //DISEASE_SIMULATIONS_GRID_H
