#ifndef MILES_EQUAL_TEMPERAMENT_TUNING_H
#define MILES_EQUAL_TEMPERAMENT_TUNING_H

#include <vector>

#include "tuning.h"

namespace miles {

Tuning EqualTemperamentTuning(uint32_t pitchesPerOctave) {
    std::vector<float> semitones(pitchesPerOctave);
    for (uint32_t i=0; i<pitchesPerOctave; i++) {
        semitones[i] = i;
    }

    return Tuning(std::move(semitones));
}

}

#endif
