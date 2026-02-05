#ifndef CANDLE_HPP  
#define CANDLE_HPP

struct Candle{
    //temps
    long long timestamp;

    //données
    double open;
    double high;
    double low;
    double close;
    double volume;

    //indicateurs
    double sma = 0.0;
    double upper_band = 0.0;
    double lower_band = 0.0;

    //signaux
    bool buy_signal = false;
    bool sell_signal = false;
};


#endif