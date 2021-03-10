#pragma once
#include <string>
class ASCIICodeGenerator
{
public: int Value;
public: ASCIICodeGenerator* Next;

private: int GetAsciiValue(char character);
private: ASCIICodeGenerator* GetASCIICodeInOrder(ASCIICodeGenerator* head);
public: ASCIICodeGenerator* ConvertStringInToAsciiCode(ASCIICodeGenerator* head, std::string value);
};

