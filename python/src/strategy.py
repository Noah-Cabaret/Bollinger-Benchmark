from abc import ABC, abstractmethod

class Strategy(ABC):
    @abstractmethod
    def apply(self,df):
        pass

class BollingerStrategy(Strategy):
    def __init__(self, window = 20, std_dev = 2.0):
        self.window = window
        self.std_dev = std_dev

    def apply(self,df):
        df["sma"] = df["close"].rolling(self.window).mean()
        df["std"] = df["close"].rolling(self.window).std()
        df["upper"] = df["sma"] + (self.std_dev * df["std"])
        df["lower"] = df["sma"] - (self.std_dev * df["std"])

        df["buy_signal"] = df["close"] < df["lower"]
        df["sell_signal"] = df["close"] > df["upper"]

        return df