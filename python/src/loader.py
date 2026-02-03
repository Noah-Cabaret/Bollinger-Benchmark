import pandas as pd

class DataLoader:
    def __init__(self, path):
        self.path = path

    def load(self):
        df = pd.read_csv(self.path)
        df["date"] = pd.to_datetime(df["date"], unit="ms")
        df = df.set_index(df["date"])
        del df["date"]
        return df
