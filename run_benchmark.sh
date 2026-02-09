#!/bin/bash

echo -e "\n   BOLLINGER BENCHMARK: PYTHON VS C++     \n "

echo -e "[Lancement du moteur C++]"
cd cpp
make --quiet 
./backtest_cpp
cd ..

echo -e "[Lancement du moteur Python]"
cd python
if [ -d "venv" ]; then
    source venv/bin/activate
    python3 main.py
    deactivate
else
    python3 main.py
fi
cd ..