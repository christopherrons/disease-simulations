#include <SFML/Graphics.hpp>
#include "../headers/simulations/RandomWalkSimulation.h"
#include "iostream"
#include "window/WindowHandler.h"

//TODO: Fix Make file location
//TODO: Add install script
int main() {
    WindowHandler windowHandler;
    windowHandler.drawBackground();
    RandomWalkSimulation simulation(1000);

    int simulationIteration = 0;
    while (simulationIteration < ConfigUtils::getGridWidth()) {
        std::cout << "Simulation Iter: " << simulationIteration << "\n";
        sf::Event event{};
        while (windowHandler.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandler.window.close();
        }
        windowHandler.window.clear();
        windowHandler.drawBackground();
        for (auto &subject : simulation.getSubjects()) {
            windowHandler.window.draw(subject.getSubjectTexture());
        }
        windowHandler.setBackgroundPixelColor(simulationIteration, simulation.nrOfSubjects, simulation.nrOfSusceptible,
                                              simulation.nrOfDeceased, simulation.nrOfImmune, simulation.nrOfInfected);

        simulation.iterateSimulation();
        windowHandler.window.display();

        simulationIteration++;
    }
    return 0;
}






