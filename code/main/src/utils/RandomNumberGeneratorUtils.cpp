//
// Created by christopher on 2021-05-08.
//

#include "../../headers/utils/RandomNumberGeneratorUtils.h"
#include <random>

double RandomNumberGeneratorUtils::getUniformRandomNumber(int min, int max) {
    std::random_device randomDevice;
    std::default_random_engine generator(randomDevice());
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}