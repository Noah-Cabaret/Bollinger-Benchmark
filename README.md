<<<<<<< HEAD
# Bollinger Benchmark: Python vs C++

Ce projet est un moteur de backtesting comparatif implémentant une stratégie de **Bandes de Bollinger** sur le Bitcoin (BTC-USDT). L'enjeu est de mesurer et d'analyser l'écart de performance entre une approche "Data Science" (Python/Pandas) et une approche "Système" (C++ natif).

## La Stratégie
=======
# 📈 Bollinger Benchmark: Python vs C++

Ce projet est un moteur de backtesting comparatif implémentant une stratégie de **Bandes de Bollinger** sur le Bitcoin (BTC-USDT). L'enjeu est de mesurer et d'analyser l'écart de performance entre une approche "Data Science" (Python/Pandas) et une approche "Système" (C++ natif).

## 🚀 La Stratégie
>>>>>>> 233a1b7d31758a663baf600c18646fc23206a59a
L'algorithme utilise les principes de retour à la moyenne (Mean Reversion) :
* **Indicateurs** : Moyenne Mobile Simple (SMA 20) et Écarts-types (±2σ).
* **Signal d'Achat** : Clôture sous la bande inférieure.
* **Signal de Vente** : Clôture au-dessus de la bande supérieure.
* **Frais de trading** : 0.1% (simulation des frais standards type Binance).



<<<<<<< HEAD
## Architecture du Projet
=======
## 🏗️ Architecture du Projet
>>>>>>> 233a1b7d31758a663baf600c18646fc23206a59a
Le projet est structuré de manière modulaire pour garantir que les deux langages traitent exactement la même logique métier :

- `/python` : Implémentation utilisant Pandas pour les calculs vectorisés.
- `/cpp` : Implémentation native (STL) pour une performance brute sans overhead.
- `/data` : Données historiques BTC-USDT au format CSV.

<<<<<<< HEAD
## Benchmarks (Résultats actuels)

| Langage | Temps d'exécution | Solde Final (Init: 1000$) | Facteur de vitesse |
| :--- | :--- | :--- | :--- |
| **Python (Pandas)** | ` ~0.755s` | `507.41$` | 1x (Référence) |
=======
## 📊 Benchmarks (Résultats actuels)

| Langage | Temps d'exécution | Solde Final (Init: 1000$) | Facteur de vitesse |
| :--- | :--- | :--- | :--- |
| **Python (Pandas)** | `0.7518s` | `906.79$` | 1x (Référence) |
>>>>>>> 233a1b7d31758a663baf600c18646fc23206a59a
| **C++ 17** | *En cours* | *À venir* | *À venir* |

### Analyse de la performance Python
Le score de **0.75s** est satisfaisant pour du traitement de données massif, mais il met en évidence le goulot d'étranglement de la boucle `iterrows()` dans le moteur de backtest. Le C++ permettra de s'affranchir de cet overhead en manipulant directement les structures de données en mémoire.



## 🛠️ Installation & Usage

### Pré-requis
- Python 3.x + Pandas
- Compilateur G++ (Standard C++17)

