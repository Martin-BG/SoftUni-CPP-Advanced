#include "Noises.h"


std::string Noises::registerNoise(const std::string &time_, const std::string &noise_) {
    size_t time = stringToTime(time_);

    /* // Cannot use structure bindings or map::try_emplace because Judge uses older C++ standard
    const auto &[noiseIt, isNew] = noises.try_emplace(noise_, time);
    auto &[sound, noise] = *noiseIt;
    */

    const auto &pair = noises.emplace(noise_, time);
    const bool isNew = pair.second;
    auto &noise = pair.first->second;

    if (!isNew)
        noise.newNoise(time);

    return noise.getNewNoiseStatistics();
}

void Noises::printStatistics(std::ostream &ostr) const {
    ostr << "----\n";

    if (noises.empty()) {
        ostr << "No noises.\n";
        return;
    }

    /* // Cannot use structure bindings Judge uses older C++ standard
    for (const auto &[sound, noise]: noises) {
        ostr << sound << ": " << noise.getFinalStatistics() << '\n';
    }
     */

    for (const auto &pair: noises) {
        ostr << pair.first << ": " << pair.second.getFinalStatistics() << '\n';
    }
}
