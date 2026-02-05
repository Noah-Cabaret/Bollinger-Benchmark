#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>  
#include "DataLoader.hpp"
#include "Strategy.hpp"
#include "Engine.hpp"
#include "Candle.hpp"

int main() {
    std::string path = "../data/BTC-USDT.csv";
    double capital_depart = 1000.0;
    double frais = 0.001; 

    
    DataLoader loader(path);
    std::vector<Candle> dataset = loader.load();
    
    if (dataset.empty()) {
        std::cerr << "Dataset vide" << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    Strategy strat(20, 2.0);
    strat.apply(dataset); 

    Engine engine(capital_depart, frais);
    engine.run_backtester(dataset);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    
    double final_balance = engine.getFinalBalance();
    double perf = ((final_balance - capital_depart) / capital_depart) * 100.0;
    std::cout << "\n[BACKTEST REPORT]" << std::endl;
    std::cout << "Data source     : " << path << std::endl;
    std::cout << "Sample size     : " << dataset.size() << " candles" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Strategy Result : " <<  perf << "%" << std::endl;
    std::cout << "Final Capital   : " << final_balance << " USD" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Engine Latency  : " << std::fixed << std::setprecision(3) << diff.count() * 1000.0 << " ms" << std::endl;
    std::cout << std::endl;
    return 0;
}