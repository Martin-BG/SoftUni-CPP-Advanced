#include <ostream>
#include <sstream>
#include "Noise.h"

void Noise::newNoise(size_t time) {
    ++number;
    last = time;
    each = (last - first) / number;
}

std::string Noise::getNewNoiseStatistics() const {
    std::ostringstream ostr;

    ostr << number;

    if (number > 1) {
        if (each > 1) {
            ostr << ", each " << each << " minutes";
        } else {
            ostr << ", each minute";
        }
    }

    return ostr.str();
}

std::string Noise::getFinalStatistics() const {
    std::ostringstream ostr;

    ostr << number;

    if (number > 1) {
        ostr << ", from " << first << " till " << last;
        if (each > 1) {
            ostr << ", each " << each << " minutes";
        } else {
            ostr << ", each minute";
        }
    } else {
        ostr << " at " << first;
    }

    return ostr.str();
}