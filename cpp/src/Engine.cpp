#include "Engine.hpp"

Engine::Engine(double initial_balance, double fee): 
balance(initial_balance),initial_balance_ref(initial_balance), fee(fee){
    position.is_active = false;
}

std::vector<Candle>& Engine::run_backtester(std::vector<Candle> &dataset){
    for(int i = 0; i < dataset.size();i++){
        if(!position.is_active && dataset[i].buy_signal){
            position.open_price = dataset[i].close;
            position.usd_size = balance  * (1 - fee);
            position.is_active = true;
        }
        else if(position.is_active && dataset[i].sell_signal){
            double trade_result = (dataset[i].close - position.open_price) / position.open_price;
            double position_value_at_exit = position.usd_size * (1 + trade_result);
            balance = position_value_at_exit * (1 - fee);
            position.is_active = false;

        }

    }
    return dataset;
}

double Engine::getFinalBalance() const{
    return balance;
}
