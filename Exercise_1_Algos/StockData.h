#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#include <stdlib.h>
class StockData //linked list of stock data imported from .csv file
{

public:
    //std::string Data; //placeholder
    std::string Date;
    double Price[5]; //Open,High,Low,Close,Adj Close
    int Volume;
    StockData *next;
#

public:
    StockData(std::string data)
    {
        //this->Data = data;
        this->next = nullptr;

        std::istringstream ds(data);
        std::getline(ds, this->Date, ',');
        std::string tmp;
        for (size_t i = 0; i < 5; i++)
        {
            std::getline(ds, tmp, ',');
            this->Price[i] = std::stof(tmp);
        }
        std::getline(ds, tmp, ',');
        this->Volume = std::stoi(tmp);
    }
    //imports stock data from a .csv file and stores it in a linked list
    static StockData *getStockDataFromFile(std::string path)
    {
        std::cout << "importing...";
        std::ifstream inFile;
        std::string line;
        inFile.open(path);
        assert(inFile.is_open());
        inFile >> line; //skip to first dataset
        inFile >> line; //space between Adj Close
        inFile >> line;
        StockData *head = new StockData(line),
                  *p1 = head;
        inFile >> line;
        while (!inFile.eof())
        {
            p1->next = new StockData(line);
            p1 = p1->next;
            inFile >> line;
            //std::cout << ": " << line << std::endl;
        }
        return head;
    }
};