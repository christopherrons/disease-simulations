// ------------------------------------------------------------------------------
// Disease Simulation
//
// (C) 2021 Christopher Herron
// email: christopherherron09@gmail.com
//
// ------------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <thread>
#include "../headers/simulations/RandomWalkSimulation.h"
#include "iostream"
#include "../headers/gui/WindowHandler.h"

int main() {

    std::string recordOption;
    std::cout << "\nType record if you wish to record: ";
    std::cin >> recordOption;

    int nrOfSubjects = 1500;

    WindowHandler windowHandler(nrOfSubjects);
    windowHandler.drawBackground();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate;

    RandomWalkSimulation simulation(nrOfSubjects);

    int simulationIteration = 0;
    windowHandler.draw(simulation, simulationIteration);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    while (simulationIteration < ConfigUtils::getGridWidth()) {
        timeSinceLastUpdate += clock.restart();

        sf::Event event{};
        while (windowHandler.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandler.window.close();
        }

        if (timeSinceLastUpdate.asSeconds() >= ConfigUtils::simulationFrameRate()) {
            windowHandler.draw(simulation, simulationIteration);
            if (recordOption == "record") {
                windowHandler.takeScreenShot(simulationIteration);
            }

            simulation.iterateSimulation();
            simulationIteration++;
        }
    }
    return 0;
}






