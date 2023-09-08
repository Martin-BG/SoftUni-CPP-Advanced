#ifndef NOISE_H
#define NOISE_H

#include <string>

class Noise {

    size_t first{};
    size_t last{};
    size_t number{1};
    size_t each{1};

public:
    Noise() = default;

    explicit Noise(size_t first_) : first(first_), last(first_) {}

    Noise(const Noise &) = default;

    Noise &operator=(const Noise &) = default;

    [[nodiscard]] size_t getFirst() const { return first; }

    [[nodiscard]] size_t getLast() const { return last; }

    [[nodiscard]] size_t getNumber() const { return number; }

    void newNoise(size_t time);

    std::string getNewNoiseStatistics() const;

    std::string getFinalStatistics() const;
};

#endif