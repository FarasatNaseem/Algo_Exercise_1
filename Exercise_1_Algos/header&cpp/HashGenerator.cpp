#include "HashGenerator.h"
#include <math.h>

unsigned long long HashGenerator::GenerateHash(std::string text)
{
	this->asciiCodeList = this->asciiCodeGenerator.ConvertStringInToAsciiCode(this->asciiCodeList, text);
	std::string hexValue = this->asciiToHexConverter.ConvertAsciiInToHexdecimalValue(this->asciiCodeList, this->hexdecimalValueGenerator);

	unsigned long long hashCode = 0;
	double baseValue = 2;

	double power = hexValue.length() - 1;

	for (int i = 0; i < hexValue.length(); i++)
	{
		unsigned long result = (unsigned long)pow(baseValue, power--);

		result = result * (int)hexValue[i];

		hashCode += (unsigned long long)result;
	}

	return hashCode;

}
