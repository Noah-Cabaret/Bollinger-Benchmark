class BacktestEngine:
    def __init__(self, initial_balance = 1000, fee = 0.001):
        self.initial_balance = initial_balance
        self.fee = fee
        self.position = None

    def run_backtest(self, df):
        data = df.copy()
        equity_history = []
        for index, row in data.iterrows():
            if self.position is None and row["buy_signal"]:
                open_price = row["close"]
                open_usd_size = self.initial_balance * (1 - self.fee)
                self.position = {
                    'open_price' : open_price,
                    'usd_size' : open_usd_size
                }
            elif self.position and row['sell_signal']:
                close_price = row["close"]
                trade_result = (close_price - self.position["open_price"]) / self.position['open_price']
                position_value_at_exit = self.position['usd_size'] * (1 + trade_result)
                self.initial_balance = position_value_at_exit * (1 - self.fee)
                self.position = None

            equity_history.append(self.initial_balance)
        
        data['equity'] = equity_history
        return data