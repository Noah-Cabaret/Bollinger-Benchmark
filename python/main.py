from src.loader import DataLoader
from src.engine import BacktestEngine
from src.strategy import BollingerStrategy
import time

def main():
    path = "../data/BTC-USDT.csv"

    loader = DataLoader(path)
    strat = BollingerStrategy(window=20, std_dev=2)
    engine = BacktestEngine(initial_balance=1000, fee=0.001)

    df = loader.load()

    start_time = time.time()
    df_with_indicators = strat.apply(df)

    balance = engine.run_backtest(df_with_indicators)
    end_time = time.time()

    duration = (end_time - start_time)
    with open("../bench_results.txt", "a") as f:
        f.write(f"python,{duration:.6f}\n")

    print(f"Python Execution Time: {duration:.6f}s")
    print(f"Final balance: {balance:.2f}$")


if __name__ == "__main__":
    main()
 