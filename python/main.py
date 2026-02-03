from src.loader import DataLoader
from src.engine import BacktestEngine
from src.strategy import BollingerStrategy
from src.plotter import plot_equity_curve,plot_signals
import time

def main():
    path = "../data/BTC-USDT.csv"
    balance = 1000
    loader = DataLoader(path)
    strat = BollingerStrategy(window=20, std_dev=2)
    engine = BacktestEngine(initial_balance=balance, fee=0.001)

    df = loader.load()

    start_time = time.time()
    df_with_indicators = strat.apply(df)

    df_results = engine.run_backtest(df_with_indicators)
    end_time = time.time()

    duration = (end_time - start_time)
    with open("../bench_results.txt", "a") as f:
        f.write(f"python,{duration:.6f}\n")

    print(f"Python Execution Time: {duration:.6f}s")
    print(f"Final balance: {df_results['equity'].iloc[-1]:.2f}$")
    
    plot_equity_curve(df_results,balance)
    plot_signals(df_results)

if __name__ == "__main__":
    main()
 