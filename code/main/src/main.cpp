#include <SFML/Graphics.hpp>
#include "../headers/simulations/RandomWalkSimulation.h"
#include "iostream"

//TODO: Fix Make file location
//TODO: Add install script

sf::Color
setPixelColor(sf::Texture &texture, int simulationIteration, int nrOfSubjects, int nrOfSusceptible, int nrOfDeceased,
              int nrOfImmune, int nrOfInfected) {
    sf::Image image = texture.copyToImage();
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
    for (int i = susceptibleHeight + infectedHeight; i < susceptibleHeight + infectedHeight + immuneHeight - addBlackBorder; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Blue);
    }
    int deceasedHeight = (nrOfDeceased * maxHeight) / nrOfSubjects;
    for (int i = susceptibleHeight + infectedHeight + immuneHeight; i < susceptibleHeight + infectedHeight + immuneHeight + deceasedHeight - addBlackBorder; i++) {
        image.setPixel(simulationIteration, i, sf::Color::Yellow);
    }
    
    texture.loadFromImage(image);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()),
                            "Random Walk Disease Spread Simulation", sf::Style::Fullscreen);
    sf::Texture texture;
    if (!texture.loadFromFile("code/resources/images/background.png")) {
        std::cout << "Noob";
    }

    window.setFramerateLimit(60);
    sf::Sprite background;
    background.setTexture(texture);

    RandomWalkSimulation simulation(1000);
    int simulationIteration = 0;
    while (simulationIteration < ConfigUtils::getGridWidth()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        simulation.iterateSimulation();
        for (auto &subject : simulation.getSubjects()) {
            window.draw(subject.getSubjectTexture());
        }
        window.display();

        setPixelColor(texture, simulationIteration, simulation.nrOfSubjects, simulation.nrOfSusceptible,
                      simulation.nrOfDeceased, simulation.nrOfImmune, simulation.nrOfInfected);

        simulationIteration++;

    }
    return 0;
}






