//
// Created by christopher on 2021-05-10.
//

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "WindowHandler.h"
#include "../../headers/utils/ConfigUtils.h"

WindowHandler::WindowHandler() {
    sf::RenderWindow window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()),
                            "Random Walk Disease Spread Simulation", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    this->backgroundTexture = sf::Texture();
    this->backgroundSprite = sf::Sprite();
    loadBackground();

}

//TODO: Clean up
void WindowHandler::setBackgroundPixelColor(int simulationIteration, int nrOfSubjects, int nrOfSusceptible,
                                            int nrOfDeceased, int nrOfImmune, int nrOfInfected) {
    sf::Image image = this->backgroundTexture.copyToImage();
    int maxHeight = ConfigUtils::getSirPlotHeight();
    int susceptibleHeight = (nrOfSusceptible * maxHeight) / nrOfSubjects;
    for (int i = 0; i < susceptibleHeight; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Green);
    }
    int infectedHeight = (nrOfInfected * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight; i < susceptibleHeight + infectedHeight; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Red);
    }
    int removedHeight = ((nrOfDeceased + nrOfImmune) * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight; i < susceptibleHeight + infectedHeight + removedHeight; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Blue);
    }
    this->backgroundTexture.loadFromImage(image);
}

const sf::RenderWindow &WindowHandler::getWindow() const {
    return window;
}

void WindowHandler::loadBackground() {
    if (!backgroundTexture.loadFromFile("code/resources/images/background.png")) {
        std::cout << "Failed to load background";
    }
    backgroundSprite.setTexture(this->backgroundTexture);
}

sf::Texture &WindowHandler::getBackgroundTexture() {
    return this->backgroundTexture;
}

sf::Sprite &WindowHandler::getBackgroundSprite() {
    return this->backgroundSprite;
}
