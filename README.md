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

The most straightforward way to use Miles is to use one of its collection of built-in scales.  In this example we print the C major scale between middle C and high C.

```cpp
#include <iostream>

#include "miles.h"

using namespace miles;

// Create a major scale
Scale scale = MajorScale();

// The frequency of low C, used as the base frequency of our scale
float lowC = 65.406f;

int main() {
    // Print the C major scale from middle C to high C
    for (uint32_t i=0; i<8; i++) {
        std::cout << scale.getFrequency(i, lowC, 2) << std::endl;
    }
}
```

### Changing the tuning

Miles' built-in scales use an appropriate tuning system by default, however this can be easily changed.  In this example we create an A minor scale with just tuning, and use it to print the frequency of the F above middle C.

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


