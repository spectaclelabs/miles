#ifndef MILES_SCALE_H
#define MILES_SCALE_H

#include <cmath>
#include <initializer_list>
#include <vector>

#include "tuning.h"
#include "equal_temperament_tuning.h"

namespace miles {

class Scale {
public:
    Scale(std::initializer_list<uint32_t> degrees,
          Tuning tuning=EqualTemperamentTuning(12)) :
        degrees(degrees), tuning(std::move(tuning)) {}

    float getFrequency(uint32_t degree, float rootFrequency,
                       uint32_t octave) {
        float frequency = rootFrequency;
        uint32_t extraOctaves = degree >= degrees.size() ?
            degree / degrees.size() : 0u;
        degree -= extraOctaves * degrees.size();
        octave += extraOctaves;
        frequency *= std::pow(tuning.getOctaveRatio(), octave);
        frequency *= tuning.getRatio(degrees[degree]);
        return frequency;
    }

private:
    std::vector<uint32_t> degrees;
    Tuning tuning;
};

}

#endif
