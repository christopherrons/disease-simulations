//
// Created by christopher on 2021-05-10.
//

#ifndef DISEASE_SIMULATIONS_WINDOWHANDLER_H
#define DISEASE_SIMULATIONS_WINDOWHANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class WindowHandler {
public:
    explicit WindowHandler();

    const sf::RenderWindow &getWindow() const;

    sf::Texture &getBackgroundTexture();

    sf::Sprite &getBackgroundSprite();

    void setBackgroundPixelColor(int simulationIteration, int nrOfSubjects, int nrOfSusceptible,
                                 int nrOfDeceased, int nrOfImmune, int nrOfInfected);

private:
    void loadBackground();

private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};

#endif //DISEASE_SIMULATIONS_WINDOWHANDLER_H
