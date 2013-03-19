#include <iostream>

#include "miles.h"

using namespace miles;

// Create a minor scale with Just tuning
Scale scale = MinorScale(JustTuning());

// The frequency of the A below middle C, used as the base frequency of our
// scale
float baseA = 220.0f;

int main() {
    // Print the F above middle C (the 6th note in the A minor scale)
    std::cout << scale.getFrequency(5, baseA, 0) << std::endl;
}
    
    
