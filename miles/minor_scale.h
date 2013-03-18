#ifndef MILES_MINOR_SCALE_H
#define MILES_MINOR_SCALE_H

#include "scale.h"
#include "equal_temperament_tuning.h"

namespace miles {

Scale MinorScale(Tuning tuning=EqualTemperamentTuning(12)) {
    return Scale({0u, 2u, 3u, 5u, 7u, 8u, 10u}, tuning);
}

}

#endif
