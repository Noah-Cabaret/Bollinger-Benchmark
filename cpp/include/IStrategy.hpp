#ifndef ISTRATEGY_HPP
#define ISTRATEGY_HPP

#include <vector>
#include "Candle.hpp"

class IStrategy{
    public:
        virtual~ IStrategy() = default;
        virtual std::vector<Candle>& apply(std::vector<Candle> &dataset) = 0;

};

#endif