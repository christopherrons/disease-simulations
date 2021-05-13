//
// Created by christopher on 2021-05-10.
//

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../headers/gui/WindowHandler.h"
#include "../../headers/utils/ConfigUtils.h"

WindowHandler::WindowHandler(int nrOfSubjects)
        : window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()), "SFML gui",
                 sf::Style::Fullscreen),
          backgroundTexture(sf::Texture()),
          backgroundSprite(sf::Sprite()),
          textFont(sf::Font()),
          totalSubjectsText(sf::Text("Total Subjects: " + std::to_string(nrOfSubjects), textFont)),
          nrOfDeceasedText(sf::Text("", textFont)),
          nrOfImmuneText(sf::Text("", textFont)),
          nrOfInfectedText(sf::Text("", textFont)),
          nrOfSusceptibleText(sf::Text("", textFont)) {

    totalSubjectsText.setOutlineThickness(1.f);
    totalSubjectsText.setFillColor(sf::Color::White);
    totalSubjectsText.setCharacterSize(20);
    totalSubjectsText.setPosition(15.f, 5.f);
    totalSubjectsText.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);

    nrOfSusceptibleText.setOutlineThickness(1.f);
    nrOfSusceptibleText.setFillColor(sf::Color::White);
    nrOfSusceptibleText.setPosition(15.f, 30.f);
    nrOfSusceptibleText.setCharacterSize(18);
    nrOfSusceptibleText.setStyle(sf::Text::Style::Bold);

    nrOfInfectedText.setOutlineThickness(1.f);
    nrOfInfectedText.setFillColor(sf::Color::White);
    nrOfInfectedText.setPosition(15.f, 55.f);
    nrOfInfectedText.setCharacterSize(18);
    nrOfInfectedText.setStyle(sf::Text::Style::Bold);

    nrOfImmuneText.setOutlineThickness(1.f);
    nrOfImmuneText.setFillColor(sf::Color::White);
    nrOfImmuneText.setPosition(15.f, 80.f);
    nrOfImmuneText.setCharacterSize(18);
    nrOfImmuneText.setStyle(sf::Text::Style::Bold);

    nrOfDeceasedText.setOutlineThickness(1.f);
    nrOfDeceasedText.setFillColor(sf::Color::White);
    nrOfDeceasedText.setPosition(15.f, 105.f);
    nrOfDeceasedText.setCharacterSize(18);
    nrOfDeceasedText.setStyle(sf::Text::Style::Bold);

    window.setFramerateLimit(60);
    loadBackground();
    loadFont();
}

//TODO: Clean up
void WindowHandler::drawSirPlot(const int simulationIteration, const int nrOfSubjects,
                                const int nrOfSusceptible, const int nrOfDeceased, const int nrOfImmune,
                                const int nrOfInfected) {
    sf::Image image = this->backgroundTexture.copyToImage();
    int maxHeight = ConfigUtils::getSirPlotHeight();
    int nrOfBlackPixels = 3;

    int susceptibleHeight = (nrOfSusceptible * maxHeight) / nrOfSubjects;
    for (int i = 0; i < susceptibleHeight - nrOfBlackPixels; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Green);
    }

    int infectedHeight = (nrOfInfected * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight; i < susceptibleHeight + infectedHeight - nrOfBlackPixels; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Red);
    }

    int immuneHeight = (nrOfImmune * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight;
         i < susceptibleHeight + infectedHeight + immuneHeight - nrOfBlackPixels; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Blue);
    }

    int deceasedHeight = (nrOfDeceased * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight + immuneHeight;
         i < susceptibleHeight + infectedHeight + immuneHeight + deceasedHeight; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Magenta);
    }
    this->backgroundTexture.loadFromImage(image);
}

void WindowHandler::loadBackground() {
    if (!this->backgroundTexture.loadFromFile("../code/resources/images/background.png")) {
        std::cout << "Failed to load background" << std::endl;
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);
}

void WindowHandler::loadFont() {
    if (this->textFont.loadFromFile("../code/resources/fonts/OpenSans-Regular.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
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

void WindowHandler::drawStatistics(const int nrOfSusceptible, const int nrOfDeceased, const int nrOfImmune,
                                   const int nrOfInfected) {
    this->window.draw(this->totalSubjectsText);

    this->nrOfDeceasedText.setString("(Magenta) Deceased: " + std::to_string(nrOfDeceased));
    this->window.draw(this->nrOfDeceasedText);

    this->nrOfSusceptibleText.setString("(Green) Susceptible : " + std::to_string(nrOfSusceptible));
    this->window.draw(this->nrOfSusceptibleText);

    this->nrOfImmuneText.setString("(Blue) Immune : " + std::to_string(nrOfImmune));
    this->window.draw(this->nrOfImmuneText);

    this->nrOfInfectedText.setString("(Red) Infected: " + std::to_string(nrOfInfected));
    this->window.draw(this->nrOfInfectedText);
}


