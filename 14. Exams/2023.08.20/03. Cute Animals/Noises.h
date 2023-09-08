#ifndef NOISES_H
#define NOISES_H

#include "Noise.h"
#include <map>
#include <string>
#include <iostream>

class Noises {

    typedef std::map<std::string, Noise> NoisesMap;
    NoisesMap noises;

    // transforms the string "+XXXX" to the number XXXX
    size_t stringToTime(const std::string & time) {
        return (time[1]-'0')*1000+(time[2]-'0')*100+(time[3]-'0')*10+time[4]-'0';        // ignore the "+" sign
    }

    public:

        std::string registerNoise(const std::string & time_, const std::string & noise_);

        void printStatistics(std::ostream & ostr) const;
};



#endif