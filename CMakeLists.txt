cmake_minimum_required(VERSION 3.19)
project(disease_simulations)

set(CMAKE_CXX_STANDARD 14)

add_executable(disease_simulations code/main/src/main.cpp code/main/src/simulations/RandomWalkSimulation.cpp code/main/headers/simulations/RandomWalkSimulation.h code/main/src/subjects/Subject.cpp code/main/headers/subjects/Subject.h code/main/src/location/Location.cpp code/main/headers/location/Location.h code/main/src/utils/RandomNumberGeneratorUtils.cpp code/main/headers/utils/RandomNumberGeneratorUtils.h code/main/src/utils/GridUtils.cpp code/main/headers/utils/GridUtils.h code/main/src/infection/Infection.cpp code/main/headers/infection/Infection.h)
target_link_libraries(disease_simulations -lsfml-graphics -lsfml-window -lsfml-system)