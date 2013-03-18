# Miles

Miles is a C++11 library for representing musical scales and tunings.  It is simple, flexible and easily supports microtonal and non-western scales.

## Using Miles

Miles is a header-only library.  To use Miles:

1. Include Miles by adding the following to your project:
    ```cpp
    #include "miles.h"
    ```

2. Add the directory which contains `miles.h` to your compiler's include path

If you need faster compilation times then you can only include the parts of Miles which you need to use, for example:

```cpp
#include "miles/major_scale.h"
```

## Examples

### Using built-in scales

The most straightforward way to use Miles is to use one of its collection of built-in scales.  In this example we print the C major scale between middle C and treble C.

```cpp
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
```

### Changing the tuning

Miles' built-in scales use an appropriate tuning system by default, however this can be easily changed.  In this example we create an A minor scale with [just tuning](http://en.wikipedia.org/wiki/Just_intonation), and use it to print the frequency of the F above middle C.

```cpp
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
```

### Creating custom scales

If Miles doesn't contain the scales you need to use then it's simple to create
a new one from a list of the scale's degrees.  In this example we create the [Phyrigian dominant scale](http://en.wikipedia.org/wiki/Phrygian_dominant_scale), and print the C# scale.

```cpp
#include <iostream>

#include "miles.h"

using namespace miles;

// A custom scale is a simple factory function returning a scale.
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
```

### Creating custom tunings

Similarly, we can create custom tunings from a list of semitone values or note ratios.

```cpp
#include <iostream>
#include <iomanip>

#include "miles.h"

using namespace miles;

// A custom tuning is a simple factory function returning a tuning
Tuning CustomTuning() {
    return Tuning({0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,                         11.f}, 2.05);
}

// Create an instance of our custom scale
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
```



