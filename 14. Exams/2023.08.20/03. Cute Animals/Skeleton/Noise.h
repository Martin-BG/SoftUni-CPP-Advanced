#ifndef NOISE_H
#define NOISE_H

#include <string>

class Noise {

    size_t first;
    size_t last;
    size_t number;
    size_t each;

    public:
        Noise() {}
        Noise(size_t first_) : number(1), last(first_), first(first_), each(1) {}
        Noise(const Noise &) = default;
        Noise & operator = (const Noise &) = default;

        int getFirst(void) const { return first; }
        int getLast(void) const { return last; }
        int getNumber(void) const { return number; }

        void newNoise(size_t time);

        std::string getNewNoiseStatistics(void) const;
        std::string getFinalStatistics(void) const;
};

#endif