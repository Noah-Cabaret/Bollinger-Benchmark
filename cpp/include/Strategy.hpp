#ifndef STRATEGY_HPP
#define STRATEGY_HPP
#include <vector>
#include "Candle.hpp"

class Strategy{
    public:
        Strategy(int window, double std_dev);

        std::vector<Candle>& apply(std::vector<Candle> &dataset);

    private:
        void calculateSMA(std::vector<Candle> &dataset);
        void calculateBands(std::vector<Candle> &dataset);
        void updateSignals(std::vector<Candle> &dataset);
        int window;
        double std_dev;

};

#endif