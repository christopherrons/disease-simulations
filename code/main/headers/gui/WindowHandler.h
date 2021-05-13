//
// Created by christopher on 2021-05-10.
//

#ifndef DISEASE_SIMULATIONS_WINDOWHANDLER_H
#define DISEASE_SIMULATIONS_WINDOWHANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "../simulations/RandomWalkSimulation.h"

class WindowHandler {
private:
    void loadBackground();

    void loadFont();

    void drawStatistics(const int nrOfSusceptible, const int nrOfDeceased, const int nrOfImmune,
                        const int nrOfInfected);

    void drawSirPlot(int simulationIteration, int nrOfSubjects, int nrOfSusceptible, int nrOfDeceased, int nrOfImmune,
                     int nrOfInfected);

public:
    WindowHandler(double nrOfSubjects);

    sf::Texture &getBackgroundTexture();

    sf::Sprite &getBackgroundSprite();

    void drawBackground();

    void draw(RandomWalkSimulation &simulation, int simulationIteration);

    void takeScreenShot(int simulationIteration);

private:
    double nrOfSubjects;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font textFont;
    sf::Text totalSubjectsText;
    sf::Text nrOfSusceptibleText;
    sf::Text nrOfDeceasedText;
    sf::Text nrOfImmuneText;
    sf::Text nrOfInfectedText;

public:
    sf::RenderWindow window;
};

#endif //DISEASE_SIMULATIONS_WINDOWHANDLER_H
