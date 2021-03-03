#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
class StockData //linked list of stock data imported from .csv file
{
    // Date,Open,High,Low,Close,Adj Close,Volume
public:
    std::string Data;
    StockData *next;
#

public:
    StockData(std::string data)
    {
        this->Data = data;
        this->next = nullptr;
    }
    static StockData *getStockDataFromFile(std::string path)
    {
        std::cout << "importing...";
        std::ifstream inFile;
        std::string line;
        inFile.open(path);
        assert(inFile.is_open());
        inFile >> line; //skip to first dataset
        inFile >> line;
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