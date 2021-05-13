# disease-simulations
This is a random walk simulation of how a disease spreads in a population. 
A subject in the population can be in one if four states:
1. Susceptible
1. Infected
1. Immune
1. Deceased

The rate at which the subjects change states is dependent on the following variables:
* Initial number of infected
* Recovery rate once infected
* Immune rate if recovered
* Death rate
* Infection Spread Radius

# Installation Linux Ubuntu
The simulation requires SFML to run. Simple run the setup.sh script to download SFML.

# Running the Simulation
The simulation is built using CMAKE and can be built and executed using the buildAndExecute.sh script. 
