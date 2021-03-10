#pragma once

#include <iostream>
#include <string>
//#include <math.h>
#include "Aktie.h"
//#include "ASCIICodeGenerator.h"
//#include "HexadecimalValueGenerator.h"
//#include "AsciiToHexConverter.h"
//#include "HashGenerator.h"
//#include <conio.h>

class HashTable
{
private: Aktie aktien[1000];

public:int GetIndexOfHashTable(unsigned long long hashCode, int arrayLength);

private:bool isIndexEmpty(int index);

private:Aktie* InsertAtStart(Aktie* aktien, Aktie aktie);

private:Aktie* InsertAtLast(Aktie* aktien, Aktie aktie);

private:Aktie* AddInList(Aktie* aktien, Aktie aktie);

public:void Add(Aktie& aktie, int index);

public:Aktie ReadDetail();

private:int GetIndexOfNode(Aktie* head, std::string kürzel);

private:int CountTotalNode(Aktie* head);

private:Aktie SearchInListByValue(Aktie* head, std::string kürzel);

public:Aktie Search(std::string kürzel);

private:Aktie* DeleteFirstIndex(Aktie* head);

private:Aktie* DeleteLastIndex(Aktie* head);

private:Aktie* deleteIndex(Aktie* head, int index);

public: void Delete(std::string kürzel);
};
