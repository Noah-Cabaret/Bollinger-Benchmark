# Bollinger Benchmark: Python vs C++

Ce projet est un moteur de backtesting comparatif implémentant une stratégie de **Bandes de Bollinger** sur le Bitcoin (BTC-USDT). L'enjeu est de mesurer et d'analyser l'écart de performance entre une approche "Data Science" (Python/Pandas) et une approche "Système" (C++ natif).

## La Stratégie
L'algorithme utilise les principes de retour à la moyenne (Mean Reversion) :
* **Indicateurs** : Moyenne Mobile Simple (SMA 20) et Écarts-types (±2σ).
* **Signal d'Achat** : Clôture sous la bande inférieure.
* **Signal de Vente** : Clôture au-dessus de la bande supérieure.
* **Frais de trading** : 0.1% (simulation des frais standards type Binance).


## Architecture du Projet
Le projet est structuré de manière modulaire pour garantir que les deux langages traitent exactement la même logique métier.
> **Note :** L'implémentation repose sur le **Design Pattern Strategy**, rendant le système nativement compatible avec n'importe quelle nouvelle stratégie de trading sans modification du cœur du moteur.

- `/python` : Implémentation utilisant Pandas pour les calculs vectorisés.
- `/cpp` : Implémentation native (STL) pour une performance brute sans overhead.
- `/data` : Données historiques BTC-USDT au format CSV.

## Benchmarks (Résultats actuels)

| Langage | Temps d'exécution | Solde Final (Init: 1000$) | Facteur de vitesse |
| :--- | :--- | :--- | :--- |
| **Python (Pandas)** | ` ~790ms` | `507.41$` | 1x (Référence) |
| **C++ 17** | `~1.1ms`| `507.41$` | ~720x |

### Analyse de la performance Python
Le score de **0.79s** est satisfaisant pour du traitement de données massif, mais il met en évidence le goulot d'étranglement de la boucle `iterrows()` dans le moteur de backtest. 

### Analyse de la performance C++
Le score de **1.1 ms** démontre l'efficacité du C++ pour le calcul quantitatif. Cette performance est atteinte grâce à :
* **Organisation optimisée des données** : L’utilisation de `std::vector` permet de ranger toutes les informations à la suite en mémoire. Cela permet à l'ordinateur de les lire d'un seul trait sans perdre de temps, garantissant une vitesse de traitement maximale.
* **Passage par référence** : Zéro copie de données entre les modules `DataLoader`, `Strategy` et `Engine`.
* **Optimisation à la compilation** : Utilisation du flag `-O3` transformant la logique en instructions machine pures.

## 🛠️ Installation & Usage

### Pré-requis
- Python 3.x + Pandas
- Compilateur G++ (Standard C++17)

### Lancer le projet

**1. Installation des dépendances Python :**
```bash
pip install -r requirements.txt
```

**2. Exécution du script Python :**
```bash
python3 main.py
```
**3. Compilation et exécution du C++ :**
```bash
cd cpp
make
./backtest_cpp
```

**3. Exécution des deux programmes**
```bash
./run_run_benchmark.sh
```