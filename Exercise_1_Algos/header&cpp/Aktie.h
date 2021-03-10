#pragma once
#include <string>
using namespace std;
class Aktie
{
public: string Name;
public: string WKN;
public: string Kürzel;
public: Aktie* next;

public: Aktie();
};

