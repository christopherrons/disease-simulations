//
// Created by christopher on 2021-05-10.
//

#ifndef DISEASE_SIMULATIONS_WINDOWHANDLER_H
#define DISEASE_SIMULATIONS_WINDOWHANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class WindowHandler {
private:
    void loadBackground();

public:
    WindowHandler();

    sf::Texture &getBackgroundTexture();

    sf::Sprite &getBackgroundSprite();

    void setBackgroundPixelColor(int simulationIteration, int nrOfSubjects, int nrOfSusceptible, int nrOfDeceased,
                                 int nrOfImmune, int nrOfInfected);

    void drawBackground();

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    sf::RenderWindow window;
};

#endif //DISEASE_SIMULATIONS_WINDOWHANDLER_H
