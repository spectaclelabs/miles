#ifndef MILES_TUNING_H
#define MILES_TUNING_H

#include <cmath>
#include <initializer_list>
#include <vector>

namespace miles {

class Tuning {
public:
    Tuning(std::initializer_list<float> semitones, float octaveRatio=2.0f) :
        Tuning(semitones, octaveRatio) {}

    Tuning(std::vector<float> semitones, float octaveRatio=2.0f) :
        semitones(std::move(semitones)), ratios(this->semitones.size()),
        octaveRatio(octaveRatio) {
        float invLength = 1.0f / this->semitones.size();
        for (uint32_t i=0; i<this->semitones.size(); i++) {
            ratios[i] = std::pow(2.0f, this->semitones[i] * invLength);  
        }
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
