#ifndef BOLLINGER_STRATEGY_HPP
#define BOLLINGER_STRATEGY_HPP

#include "IStrategy.hpp"

class BollingerStrategy : public IStrategy {
    public:
        BollingerStrategy(int window, double std_dev);

        std::vector<Candle>& apply(std::vector<Candle> &dataset) override;

    private:
        void calculateSMA(std::vector<Candle> &dataset);
        void calculateBands(std::vector<Candle> &dataset);
        void updateSignals(std::vector<Candle> &dataset);
        int window;
        double std_dev;

};

#endif