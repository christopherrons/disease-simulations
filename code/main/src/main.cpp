#include <SFML/Graphics.hpp>
#include "../headers/simulations/RandomWalkSimulation.h"
#include "iostream"
#include "../headers/gui/WindowHandler.h"

//TODO: Fix Make file location
//TODO: Add install script
//TODO: Switch to initialization list
int main() {

    WindowHandler windowHandler;
    windowHandler.drawBackground();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    double frameRate = 1.f / 60;

    RandomWalkSimulation simulation(1000);
    int simulationIteration = 0;

    while (simulationIteration < ConfigUtils::getGridWidth()) {
        timeSinceLastUpdate += clock.restart();
        //std::cout << "Simulation Iter: " << simulationIteration << "\n";
        sf::Event event{};
        while (windowHandler.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandler.window.close();
        }

        //  std::cout << timeSinceLastUpdate.asSeconds() << std::endl;
        if (timeSinceLastUpdate.asSeconds() >= frameRate) {
            windowHandler.window.clear();
            windowHandler.drawBackground();
            for (auto &subject : simulation.getSubjects()) {
                windowHandler.window.draw(subject.getSubjectTexture());
            }
            windowHandler.setBackgroundPixelColor(simulationIteration, simulation.nrOfSubjects,
                                                  simulation.nrOfSusceptible, simulation.nrOfDeceased,
                                                  simulation.nrOfImmune, simulation.nrOfInfected);

            simulation.iterateSimulation();
            windowHandler.window.display();

            simulationIteration++;
        }
    }
    return 0;
}






