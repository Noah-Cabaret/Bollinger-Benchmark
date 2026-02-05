#ifndef DATALOADER_HPP
#define DATALOADER_HPP
#include <string>
#include <vector>
#include "Candle.hpp"


class DataLoader{
    public:
        DataLoader(std::string path);

        std::vector<Candle> load();

    private:
        std::string path;
};





#endif