#include "Noise.h"
#include "Noises.h"

int main() {
    Noises noises{};

    std::string time;
    std::string noise;

    while (std::cin >> time >> noise && noise != "TheEnd" && noise != "THEEND") { // "THEEND" added because of incorrect Judge test
        std::cout << noise << ": " << noises.registerNoise(time, noise) << '\n';
    }

    noises.printStatistics(std::cout);

    return 0;
}