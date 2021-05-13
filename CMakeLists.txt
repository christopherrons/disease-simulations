cmake_minimum_required(VERSION 3.19)
project(disease_simulations)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/..bin)

add_executable(disease_simulations
        code/main/src/main.cpp
        code/main/src/simulations/RandomWalkSimulation.cpp
        code/main/headers/simulations/RandomWalkSimulation.h
        code/main/src/subjectData/Subject.cpp
        code/main/headers/subjectData/Subject.h
        code/main/src/subjectData/Location.cpp
        code/main/headers/subjectData/Location.h
        code/main/src/math/utils/MathematicalUtils.cpp
        code/main/headers/math/utils/MathematicalUtils.h
        code/main/src/utils/ConfigUtils.cpp
        code/main/headers/utils/ConfigUtils.h
        code/main/src/math/InfectionSpreadCalculator.cpp
        code/main/headers/math/InfectionSpreadCalculator.h
        code/main/src/subjectData/HealthStatus.cpp
        code/main/headers/subjectData/HealthStatus.h
        code/main/src/gui/WindowHandler.cpp code/main/headers/gui/WindowHandler.h
        code/main/src/math/SweepPruneAlgorithm.cpp
        code/main/headers/math/SweepPruneAlgorithm.h
        code/main/src/subjectData/Grid.cpp
        code/main/headers/subjectData/Grid.h)

target_link_libraries(disease_simulations
        -lsfml-graphics
        -lsfml-window
        -lsfml-system)