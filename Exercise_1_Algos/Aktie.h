#pragma once
#include <string>
#include "Price.h"
using namespace std;
class Aktie
{
	/*
	*
	* Namen, WKN und K�rzel
	*/

public: string Name;
	  string WKN;
	  string K�rzel;

private: Price price;

public: Aktie(string name, string wkn, string k�rzel)
{
	this->Name = name;
	this->WKN = wkn;
	this->K�rzel = K�rzel;
}

public: void Import()
{
	// Logic.
}
};

