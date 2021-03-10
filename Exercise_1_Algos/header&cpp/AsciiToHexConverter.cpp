#include "AsciiToHexConverter.h"
#include "HexadecimalValueGenerator.h"

std::string AsciiToHexConverter::ConvertAsciiInToHexdecimalValue(ASCIICodeGenerator* asciiCodeGenerator, HexadecimalValueGenerator hexdecimalValueGenerator)
{
	std::string hexDecimalValue = "";

	for (asciiCodeGenerator; asciiCodeGenerator != NULL; asciiCodeGenerator = asciiCodeGenerator->Next)
	{
		hexDecimalValue += hexdecimalValueGenerator.GenerateHexadecimalValue(asciiCodeGenerator->Value);
	}

	return hexDecimalValue;
}
