// HashCodeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <math.h>
#include "Aktie.h"
#include "ASCIICodeGenerator.h"
#include "HexadecimalValueGenerator.h"
#include "AsciiToHexConverter.h"
#include "HashGenerator.h"
#include <conio.h>
#include "HashTable.h"

int main()
{
	Aktie aktie = Aktie();
	HashTable hashTable = HashTable();
	while (true)
	{
		std::string text;

		Aktie detail = hashTable.ReadDetail();
		text = detail.Kürzel;

		HashGenerator hashGenerator = HashGenerator();
		unsigned long long hashOfString = hashGenerator.GenerateHash(text);
		int index =  hashTable.GetIndexOfHashTable(hashOfString, 1000);
		std::cout << index << std::endl;
		hashTable.Add(detail, index);
	}

	return 0;
}
