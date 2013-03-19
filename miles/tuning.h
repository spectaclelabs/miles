#ifndef MILES_TUNING_H
#define MILES_TUNING_H

#include <cmath>
#include <vector>

#include "constants.h"

namespace miles {

class Tuning {
public:
    Tuning(std::vector<float> semitones, float octaveRatio=2.0f) :
        semitones(std::move(semitones)), ratios(this->semitones.size()),
        octaveRatio(octaveRatio) {
        float invLength = 1.0f / this->semitones.size();
        for (uint32_t i=0; i<this->semitones.size(); i++) {
            ratios[i] = std::pow(2.0f, this->semitones[i] * invLength);  
        }
    }

    static Tuning fromRatios(std::vector<float> ratios,
                             float octaveRatio=2.0f) {
        std::vector<float> semitones(ratios.size());
        for (uint32_t i=0; i<ratios.size(); i++) {
            semitones[i] = ratios.size() * std::log(ratios[i]) * miles::INVLN2;
        }
        return Tuning(std::move(semitones), octaveRatio);
    }
 

    float getRatio(uint32_t index) {
        return ratios[index];
    }

    float getSemitone(uint32_t index) {
        return semitones[index];
    }

    float getOctaveRatio() {
        return octaveRatio;
    }

private:
    std::vector<float> semitones;
    std::vector<float> ratios;
    float octaveRatio;
};

}

#endif
