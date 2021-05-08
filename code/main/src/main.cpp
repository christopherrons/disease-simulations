#include <SFML/Graphics.hpp>
#include <thread>
#include "../headers/simulations/RandomWalkSimulation.h"

//TODO: Fix Make file location
//TODO: Add install script

int main() {
    sf::RenderWindow window(sf::VideoMode(GridUtils::getGridWidth(), GridUtils::getGridHeight()),
                            "Random Walk Disease Spread Simulation");
                           // sf::Style::Fullscreen);
    window.setFramerateLimit(30);
    RandomWalkSimulation simulation(5000);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        simulation.iterateSimulation();
        for (auto &subject : simulation.getSubjects()) {
            window.draw(subject.getSubjectTexture());
        }
        window.display();
    }

    return 0;
}

