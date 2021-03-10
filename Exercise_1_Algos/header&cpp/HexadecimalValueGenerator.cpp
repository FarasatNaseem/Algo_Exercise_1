#include "HexadecimalValueGenerator.h"

int HexadecimalValueGenerator::GetRest(int value, int divisor)
{
    return value % divisor;
}

int HexadecimalValueGenerator::Divide(int value, int divisor)
{
    return value / divisor;
}

std::string HexadecimalValueGenerator::GetHexadecimalValueInCorrectOrder(std::string hexadecimalValue)
{
    std::reverse(hexadecimalValue.begin(), hexadecimalValue.end());

    return hexadecimalValue;
}

std::string HexadecimalValueGenerator::GenerateHexadecimalValue(int value)
{
	std::string hexDecimalValue = "";
	int rest = 0;
	int divideResult = 0;

	for (int i = value; value >= this->baseOfHexadecimalNumber; i++)
	{
		rest = this->GetRest(value, this->baseOfHexadecimalNumber);
		divideResult = this->Divide(value, this->baseOfHexadecimalNumber);

		value = divideResult;
		hexDecimalValue += rest;
	}

	hexDecimalValue += divideResult;
	hexDecimalValue = this->GetHexadecimalValueInCorrectOrder(hexDecimalValue);

	return hexDecimalValue;
}
