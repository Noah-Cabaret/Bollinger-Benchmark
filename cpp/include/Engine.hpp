#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <string>
#include <vector>
#include "Candle.hpp"

struct Position{
    double open_price = 0.0;
    double usd_size = 0.0;
    bool is_active = false; 
};

class Engine{
    public:
        Engine(double initial_balance,double fee);

        std::vector<Candle>& run_backtester(std::vector<Candle> &dataset);

        double getFinalBalance() const;

    private:
        double initial_balance_ref;
        double balance;
        double fee;
        Position position;


};


#endif