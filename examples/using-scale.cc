#include <iostream>

#include "miles.h"

using namespace miles;

// Create a major scale
Scale scale = MajorScale();

// The frequency of low C, used as the base frequency of our scale
float lowC = 65.406f;

int main() {
    // Print the C major scale from middle C to treble C
    for (uint32_t i=0; i<8; i++) {
        std::cout << scale.getFrequency(i, lowC, 2) << std::endl;
    }
}
    
    
