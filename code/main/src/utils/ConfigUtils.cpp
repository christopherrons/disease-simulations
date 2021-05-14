//
// Created by christopher on 2021-05-08.
//

#include "../../headers/utils/ConfigUtils.h"

int ConfigUtils::getGridWidth() {
    return 1920;
}

int ConfigUtils::getGridHeight() {
    return 1080;
}

int ConfigUtils::getSirPlotHeight() {
    return 200;
}

double ConfigUtils::nrOfGridsPerRow() {
    return 10.0;
}

sf::Color ConfigUtils::infectedColor() {
    return {238, 105, 105};
}

sf::Color ConfigUtils::susceptibleColor() {
    return {44,206,125};
}

sf::Color ConfigUtils::immuneColor() {
    return {38, 82, 181};
}

sf::Color ConfigUtils::deseasedColor() {
    return {138,21,174};
}

float ConfigUtils::simulationFrameRate() {
    return 1.f / 30;
}


