import matplotlib.pyplot as plt

def plot_equity_curve(df_results, initial_balance):
    plt.figure(figsize=(12, 6))
    
    first_price = df_results['close'].iloc[0]
    df_results['buy_and_hold'] = (df_results['close'] / first_price) * initial_balance
    
    plt.plot(df_results.index, df_results['equity'], label='Stratégie Bollinger', color='blue')
    plt.plot(df_results.index, df_results['buy_and_hold'], label='Buy & Hold (BTC)', color='orange')
    
    plt.title("Comparaison de la Performance : Bollinger vs Buy & Hold")
    plt.ylabel("Valeur du portefeuille ($)")
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.savefig("../equity_curve.png")


def plot_signals(df_results):
    df_zoom = df_results.tail(200).copy()
    
    plt.figure(figsize=(15, 8))
    
    plt.plot(df_zoom.index, df_zoom['close'], label='Prix Close', color='black')
    plt.plot(df_zoom.index, df_zoom['upper'], label='Bande Haute', color='red', linestyle='--', alpha=0.5)
    plt.plot(df_zoom.index, df_zoom['lower'], label='Bande Basse', color='green', linestyle='--', alpha=0.5)
    
    # Espace entre les bandes
    plt.fill_between(df_zoom.index, df_zoom['lower'], df_zoom['upper'], color='gray', alpha=0.1)

    buys = df_zoom[df_zoom['buy_signal']]
    plt.scatter(buys.index, buys['close'], marker='^', color='green', s=100, label='buy siganl', zorder=5)

    sells = df_zoom[df_zoom['sell_signal']]
    plt.scatter(sells.index, sells['close'], marker='v', color='red', s=100, label='sell signal', zorder=5)

    plt.title("Zoom sur les 200 dernières bougies")
    plt.legend()
    plt.grid(True, alpha=0.2)
    
    plt.savefig("../signals_zoom.png")
