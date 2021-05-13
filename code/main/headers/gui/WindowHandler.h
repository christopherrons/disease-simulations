//
// Created by christopher on 2021-05-10.
//

#ifndef DISEASE_SIMULATIONS_WINDOWHANDLER_H
#define DISEASE_SIMULATIONS_WINDOWHANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class WindowHandler {
private:
    void loadBackground();

    void loadFont();

public:
    WindowHandler(int nrOfSubjects);

    sf::Texture &getBackgroundTexture();

    sf::Sprite &getBackgroundSprite();

    void drawSirPlot(int simulationIteration, int nrOfSubjects, int nrOfSusceptible, int nrOfDeceased,
                     int nrOfImmune, int nrOfInfected);

    void drawBackground();

    void drawStatistics(const int nrOfSusceptible, const int nrOfDeceased, const int nrOfImmune,
                        const int nrOfInfected);

private:
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
