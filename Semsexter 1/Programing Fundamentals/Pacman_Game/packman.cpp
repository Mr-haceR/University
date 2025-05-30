#include <iostream>

int manualSmoothRandom(int& current, int min, int max, int stepSize = 2) {
    // Basic PRNG seed update (LCG)
    static unsigned int seed = 12345;
    seed = 1664525 * seed + 1013904223;

    // Get a delta in range [-stepSize, +stepSize]
    int delta = (int)(seed % (2 * stepSize + 1)) - stepSize;

    // Apply delta to current value
    current += delta;

    // Clamp within bounds
    if (current < min) current = min;
    if (current > max) current = max;

    return current;
}



int main() {
    int value = 5; // Starting point
    for (int i = 0; i < 20; ++i) {
        std::cout << manualSmoothRandom(value, 1, 10) << " ";
    }
    return 0;
}

