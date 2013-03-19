#include <iostream>
#include <iomanip>

#include "miles.h"

using namespace miles;

// A custom tuning is a simple factory function returning a tuning
Tuning CustomTuning() {
    return Tuning({0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
                   11.f}, 2.05);
}

// Create two scale, one using the standard tuning and one using our custom
// tuning
Scale scaleA = MajorScale();
Scale scaleB = MajorScale(CustomTuning());

// The frequency of low C, used as the base frequency of our scale
float lowC = 65.406f;

int main() {
    // Print the two scales side by side for comparison
    std::cout << std::setw(8) << "ET";
    std::cout << std::setw(8) << "Custom" << std::endl;
    for (uint32_t i=0; i<8; i++) {
        std::cout << std::setw(8) << scaleA.getFrequency(i, lowC, 2);
        std::cout << std::setw(8) << scaleB.getFrequency(i, lowC, 2);
        std::cout << std::endl;
    }
}
    
    
