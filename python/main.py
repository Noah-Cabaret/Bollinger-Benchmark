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

    duration_ms = (end_time - start_time) * 1000
    final_balance = df_results['equity'].iloc[-1]
    perf = ((final_balance - balance) / balance) * 100

    print("\n[BACKTEST REPORT (PYTHON)]")
    print(f"Data source     : {path}")
    print(f"Sample size     : {len(df)} candles")
    print("--------------------------------------------")
    print(f"Strategy Result : {perf:.2f}%")
    print(f"Final Capital   : {final_balance:.2f} USD")
    print("--------------------------------------------")
    print(f"Engine Latency  : {duration_ms:.3f} ms")
    print("")
    plot_equity_curve(df_results,balance)
    plot_signals(df_results)

if __name__ == "__main__":
    main()
 