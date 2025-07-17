#ifndef HILO_H
#define HILO_H

#include "Random.h"

namespace Constants {
    const int lowerBound{1};
    const int upperBound{100};
    const int maxTries{7};
}

bool calculateResult(int guess, int hiddenNumber);

#endif
