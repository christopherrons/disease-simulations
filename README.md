# Disease Spread Simulation
This is a random walk simulation of how a disease spreads in a population. 

# Youtube Link
https://www.youtube.com/watch?v=zxPBKeA46sE

# Simulation Parameters
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
* Step length when walking randomly

# Installation Linux Ubuntu
The simulation requires SFML to run and FFmpeg to create a recording. Simple run the setup.sh script:`./setup.sh`

# Running the Simulation
The simulation is built using Cmake and can be built and executed using the buildAndExecute.sh script:
`./buildAndExecute.sh`

# Create a Recording
When running the app opted for recording then once the simulation is finished run the createRecording.sh script:
`./createRecording.sh`
