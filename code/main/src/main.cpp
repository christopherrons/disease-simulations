#include <SFML/Graphics.hpp>
#include "../headers/simulations/RandomWalkSimulation.h"
#include "../headers/utils/GridUtils.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(GridUtils::getGridWidth(),  GridUtils::getGridHeight()), "SFML works!");
    RandomWalkSimulation simulation(1000);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        int nrOfSimulationIterations = 10;
        while (nrOfSimulationIterations > 0) {
            window.clear();
            simulation.iterateSimulation();
            for (auto &subject : simulation.getSubjects()) {
                window.draw(subject.getSubjectTexture());
            }
            window.display();
            nrOfSimulationIterations--;
        }
    }

    return 0;
}

