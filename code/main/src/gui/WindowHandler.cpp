//
// Created by christopher on 2021-05-10.
//

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "../../headers/gui/WindowHandler.h"
#include "../../headers/utils/ConfigUtils.h"

WindowHandler::WindowHandler()
        : window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()), "SFML gui", sf::Style::Fullscreen),
          backgroundTexture(sf::Texture()),
          backgroundSprite(sf::Sprite()) {

    window.setFramerateLimit(60);
    loadBackground();
}

//TODO: Clean up
void
WindowHandler::setBackgroundPixelColor(const int simulationIteration, const int nrOfSubjects, const int nrOfSusceptible,
                                       const int nrOfDeceased, const int nrOfImmune, const int nrOfInfected) {
    sf::Image image = this->backgroundTexture.copyToImage();
    int maxHeight = ConfigUtils::getSirPlotHeight();
    int addBlackBorder = 3;
    int susceptibleHeight = (nrOfSusceptible * maxHeight) / nrOfSubjects;
    for (int i = 0; i < susceptibleHeight - addBlackBorder; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Green);
    }
    int infectedHeight = (nrOfInfected * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight; i < susceptibleHeight + infectedHeight - addBlackBorder; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Red);
    }
    int immuneHeight = (nrOfImmune * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight;
         i < susceptibleHeight + infectedHeight + immuneHeight - addBlackBorder; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Blue);
    }
    int deceasedHeight = (nrOfDeceased * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight + immuneHeight;
         i < susceptibleHeight + infectedHeight + immuneHeight + deceasedHeight - addBlackBorder; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Yellow);
    }
    this->backgroundTexture.loadFromImage(image);
}

void WindowHandler::loadBackground() {
    if (!this->backgroundTexture.loadFromFile("code/resources/images/background.png")) {
        std::cout << "Failed to load background" << std::endl;
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);
}

sf::Texture &WindowHandler::getBackgroundTexture() {
    return this->backgroundTexture;
}

sf::Sprite &WindowHandler::getBackgroundSprite() {
    return this->backgroundSprite;
}

void WindowHandler::drawBackground() {
    this->window.draw(this->backgroundSprite);
}

