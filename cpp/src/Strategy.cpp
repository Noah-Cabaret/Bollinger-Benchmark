#include "Strategy.hpp"
#include <cmath>

Strategy::Strategy(int window, double std_dev) : window(window), std_dev(std_dev){}

std::vector<Candle>& Strategy::apply(std::vector<Candle> &dataset){
    calculateSMA(dataset);
    calculateBands(dataset);
    updateSignals(dataset);
    return dataset;
}

void Strategy::calculateSMA(std::vector<Candle> &dataset){
    for(int i = (window - 1); i < dataset.size();i++){
        double sum = 0.0;
        for(int j = i - (window -1); j <= i; j++){
            sum += dataset[j].close;
        }
        dataset[i].sma = sum / window;
    }
}

void Strategy::calculateBands(std::vector<Candle> &dataset){
    for(int i = (window - 1); i < dataset.size();i++){
        double current_sma = dataset[i].sma;
        double sum_sq_diff = 0.0;
        for(int j = i - (window -1); j <= i; j++){
            double diff = (dataset[j].close - current_sma);
            sum_sq_diff += diff * diff;
        }
        double variance = sum_sq_diff / (window-1);
        double std_d = std::sqrt(variance);

        dataset[i].lower_band = current_sma - (std_dev * std_d);
        dataset[i].upper_band = current_sma + (std_dev * std_d);
    }

}

void Strategy::updateSignals(std::vector<Candle> &dataset){
    for(int i = (window - 1); i < dataset.size();i++){
        if(dataset[i].close < dataset[i].lower_band){
            dataset[i].buy_signal = true;
        }
        else if(dataset[i].close > dataset[i].upper_band){
            dataset[i].sell_signal = true;
        }
    }
}
