#ifndef MILES_MAJOR_SCALE_H
#define MILES_MAJOR_SCALE_H

#include "scale.h"
#include "equal_temperament_tuning.h"

namespace miles {

Scale MajorScale(Tuning tuning=EqualTemperamentTuning(12)) {
    return Scale({0u, 2u, 4u, 5u, 7u, 9u, 11u}, tuning);
}

}

#endif
