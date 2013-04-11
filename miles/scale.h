#ifndef MILES_SCALE_H
#define MILES_SCALE_H

#include <cmath>
#include <vector>

#include "tuning.h"
#include "equal_temperament_tuning.h"

namespace miles {

class Scale {
public:
    Scale(std::vector<uint32_t> degrees,
          Tuning tuning=EqualTemperamentTuning(12)) :
        degrees(degrees), tuning(std::move(tuning)) {}

    float getFrequency(int degree, float rootFrequency,
                       int octave) {
        float frequency = rootFrequency;

        float fDegree = degree;
        float size = degrees.size();

        int extraOctaves = fDegree < 0.f || fDegree >= size ?
            std::floor(fDegree / size) : 0u;
        degree -= extraOctaves * size;
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
