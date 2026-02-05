#include <iostream>
#include <fstream>
#include <sstream>
#include "DataLoader.hpp"

DataLoader::DataLoader(std::string path) : path(path){}

std::vector<Candle> DataLoader::load(){
    std::vector<Candle> dataset;
    std::ifstream file(path);

    if(!file.is_open()){
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << path << std::endl;
        return dataset;
    }
    std::string line, cell;
    std::getline(file,line);

    while(std::getline(file,line)){
        std::stringstream ss(line);
        Candle c;
        std::getline(ss,cell,','); c.timestamp = std::stoll(cell);
        std::getline(ss,cell,','); c.open = std::stod(cell);
        std::getline(ss,cell,','); c.high = std::stod(cell);
        std::getline(ss,cell,','); c.low = std::stod(cell);
        std::getline(ss,cell,','); c.close = std::stod(cell);
        std::getline(ss,cell,','); c.volume = std::stod(cell);
        dataset.push_back(c);
    }
    file.close();
    return dataset;
}