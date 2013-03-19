#include <iostream>

#include "miles.h"

using namespace miles;

// A custom scale is a simple factory function returning a scale
Scale CustomScale(Tuning tuning=EqualTemperamentTuning(12)) {
    return Scale({0u, 1u, 3u, 5u, 7u, 8u, 10u}, tuning);
}

// Create an instance of our custom scale
Scale scale = CustomScale();

// The frequency of low C#, used as the base frequency of our scale
float lowCSharp = 69.296f;

int main() {
    // Print our scale from low C# to bass C#
    for (uint32_t i=0; i<8; i++) {
        std::cout << scale.getFrequency(i, lowCSharp, 0) << std::endl;
    }
}
    
    
