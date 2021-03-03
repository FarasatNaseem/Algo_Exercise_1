#pragma once
#include <string>
#include "Price.h"
using namespace std;
class Aktie
{
	/*
	*
	* Namen, WKN und Kürzel
	*/

public: string Name;
	  string WKN;
	  string Kürzel;

private: Price price;

public: Aktie(string name, string wkn, string kürzel)
{
	this->Name = name;
	this->WKN = wkn;
	this->Kürzel = Kürzel;
}

public: void Import()
{
	// Logic.
}
};

