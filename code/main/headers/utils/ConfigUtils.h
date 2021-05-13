//
// Created by christopher on 2021-05-08.
//

#ifndef DISEASE_SIMULATIONS_CONFIGUTILS_H
#define DISEASE_SIMULATIONS_CONFIGUTILS_H


#include <SFML/Graphics/Color.hpp>

class ConfigUtils {
public:
    static int getGridWidth();

    static int getGridHeight();

    static int getSirPlotHeight();

    static double nrOfGridsPerRow();

    static sf::Color infectedColor();

    static sf::Color immuneColor();

    static sf::Color susceptibleColor();

    static sf::Color deseasedColor();

    static float simulationFrameRate();
};


#endif //DISEASE_SIMULATIONS_CONFIGUTILS_H
