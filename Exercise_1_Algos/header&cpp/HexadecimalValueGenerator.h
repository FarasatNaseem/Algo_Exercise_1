#pragma once
#include <string>
class HexadecimalValueGenerator
{
private: int baseOfHexadecimalNumber = 16;

private: int GetRest(int value, int divisor);
private: int Divide(int value, int divisor);
private: std::string GetHexadecimalValueInCorrectOrder(std::string hexadecimalValue);

public: std::string GenerateHexadecimalValue(int value);
};

