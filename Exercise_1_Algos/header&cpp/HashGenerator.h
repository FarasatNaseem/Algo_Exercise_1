#pragma once
#include "ASCIICodeGenerator.h"
#include "HexadecimalValueGenerator.h"
#include "AsciiToHexConverter.h"

class HashGenerator
{
private: ASCIICodeGenerator asciiCodeGenerator = ASCIICodeGenerator();
private: ASCIICodeGenerator* asciiCodeList = nullptr;
private: HexadecimalValueGenerator hexdecimalValueGenerator = HexadecimalValueGenerator();
private: AsciiToHexConverter asciiToHexConverter = AsciiToHexConverter();
public: unsigned long long GenerateHash(std::string something);
};

