#pragma once
class HashCodeGenerator
{
private: ASCIICodeGenerator asciiCodeGenerator = ASCIICodeGenerator();
private: ASCIICodeGenerator* asciiCodeList = nullptr;
private: HexadecimalValueGenerator hexdecimalValueGenerator = HexadecimalValueGenerator();
private: AsciiToHexConverter asciiToHexConverter = AsciiToHexConverter();
};

