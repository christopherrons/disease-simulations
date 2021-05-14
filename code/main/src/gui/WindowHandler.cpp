//
// Created by christopher on 2021-05-10.
//

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../headers/gui/WindowHandler.h"
#include "../../headers/utils/ConfigUtils.h"
#include <cmath>

WindowHandler::WindowHandler(double nrOfSubjects)
        : nrOfSubjects(nrOfSubjects),
          window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()), "Random Walk Simulation", sf::Style::Fullscreen),
          backgroundTexture(sf::Texture()),
          backgroundSprite(sf::Sprite()),
          textFont(sf::Font()),
          totalSubjectsText(sf::Text("Total Subjects: " + std::to_string((int) nrOfSubjects), textFont)),
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

    window.setFramerateLimit(30);
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
        image.setPixel(simulationIteration, i, ConfigUtils::susceptibleColor());
    }

    int infectedHeight = (nrOfInfected * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight; i < susceptibleHeight + infectedHeight - nrOfBlackPixels; i++) {
        image.setPixel(simulationIteration, i, ConfigUtils::infectedColor());
    }

    int immuneHeight = (nrOfImmune * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight;
         i < susceptibleHeight + infectedHeight + immuneHeight - nrOfBlackPixels; i++) {
        image.setPixel(simulationIteration, i, ConfigUtils::immuneColor());
    }

    int deceasedHeight = (nrOfDeceased * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight + immuneHeight;
         i < susceptibleHeight + infectedHeight + immuneHeight + deceasedHeight; i++) {
        image.setPixel(simulationIteration, i, ConfigUtils::deseasedColor());
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

    this->nrOfDeceasedText.setString("(Magenta) Deceased: " + std::to_string(nrOfDeceased) + " / " +
                                     std::to_string((nrOfDeceased / this->nrOfSubjects) * 100).substr(0, 4) + " %");
    this->window.draw(this->nrOfDeceasedText);

    this->nrOfSusceptibleText.setString("(Green) Susceptible : " + std::to_string(nrOfSusceptible) + " / " +
                                        std::to_string((nrOfSusceptible / this->nrOfSubjects) * 100).substr(0, 4) +
                                        "%");
    this->window.draw(this->nrOfSusceptibleText);

    this->nrOfImmuneText.setString("(Blue) Immune : " + std::to_string(nrOfImmune) + " / " +
                                   std::to_string((nrOfImmune / this->nrOfSubjects) * 100).substr(0, 4) + "%");
    this->window.draw(this->nrOfImmuneText);

    this->nrOfInfectedText.setString("(Red) Infected: " + std::to_string(nrOfInfected) + " / " +
                                     std::to_string((nrOfInfected / this->nrOfSubjects) * 100).substr(0, 4) +
                                     "%");
    this->window.draw(this->nrOfInfectedText);
}

void WindowHandler::draw(RandomWalkSimulation &simulation, int simulationIteration) {
    this->window.clear();
    this->drawBackground();
    for (auto &subject : simulation.getSubjects()) {
        this->window.draw(subject.getSubjectTexture());
    }
    this->drawStatistics(simulation.nrOfSusceptible, simulation.nrOfDeceased,
                         simulation.nrOfImmune, simulation.nrOfInfected);
    this->drawSirPlot(simulationIteration, simulation.nrOfSubjects,
                      simulation.nrOfSusceptible, simulation.nrOfDeceased,
                      simulation.nrOfImmune, simulation.nrOfInfected);

    this->window.display();
    }

void WindowHandler::takeScreenShot(int simulationIteration) {
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);
    if (texture.copyToImage().saveToFile("../recording/images/screenshot_" + std::to_string(simulationIteration) + ".png"))   {
        std::cout << "Screenshot saved" << std::endl;
    } else {
        std::cout << "NOT SAVED" << std::endl;
    }
}




