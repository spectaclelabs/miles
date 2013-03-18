#ifndef MILES_JUST_TUNING_H
#define MILES_JUST_TUNING_H

#include <vector>

#include "tuning.h"

namespace miles {

Tuning JustTuning() {
    return Tuning::fromRatios({1.f, 16.f/15.f, 9.f/8.f, 6.f/5.f,
                               5.f/4.f, 4.f/3.f, 45.f/32.f, 3.f/2.f,
                               8.f/5.f, 5.f/3.f, 9.f/5.f, 15.f/8});
}

}

#endif
