// ------------------------------------------------------------------------------
// Disease Simulation
//
// (C) 2021 Christopher Herron
// email: christopherherron09@gmail.com
//
// ------------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "../headers/simulations/RandomWalkSimulation.h"
#include "iostream"
#include "../headers/gui/WindowHandler.h"

//TODO: Fix Make file location
//TODO: Add install script
//TODO: Switch to initialization list
int main() {
    int nrOfSubjects = 1500;
    WindowHandler windowHandler(nrOfSubjects);
    windowHandler.drawBackground();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    double frameRate = 1.f / 60;

    RandomWalkSimulation simulation(nrOfSubjects);
    int simulationIteration = 0;

    while (simulationIteration < ConfigUtils::getGridWidth()) {
        timeSinceLastUpdate += clock.restart();
        sf::Event event{};
        while (windowHandler.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandler.window.close();
        }

        if (timeSinceLastUpdate.asSeconds() >= frameRate) {
            windowHandler.window.clear();
            windowHandler.drawBackground();
            for (auto &subject : simulation.getSubjects()) {
                windowHandler.window.draw(subject.getSubjectTexture());
            }
            windowHandler.drawStatistics(simulation.nrOfSusceptible, simulation.nrOfDeceased,
                                         simulation.nrOfImmune, simulation.nrOfInfected);
            windowHandler.drawSirPlot(simulationIteration, simulation.nrOfSubjects,
                                      simulation.nrOfSusceptible, simulation.nrOfDeceased,
                                      simulation.nrOfImmune, simulation.nrOfInfected);

            simulation.iterateSimulation();
            windowHandler.window.display();

            simulationIteration++;
        }
    }
    return 0;
}






