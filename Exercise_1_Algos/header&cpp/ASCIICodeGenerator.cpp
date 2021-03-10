#include "ASCIICodeGenerator.h"

int ASCIICodeGenerator::GetAsciiValue(char character)
{
	return (int)character;
}

ASCIICodeGenerator* ASCIICodeGenerator::GetASCIICodeInOrder(ASCIICodeGenerator* head)
{
	ASCIICodeGenerator* first = NULL;
	ASCIICodeGenerator* middle = head;
	ASCIICodeGenerator* second = head;

	while (second != NULL)
	{
		second = second->Next;
		middle->Next = first;
		first = middle;
		middle = second;
	}

	head = first;

	return head;
}

ASCIICodeGenerator* ASCIICodeGenerator::ConvertStringInToAsciiCode(ASCIICodeGenerator* head, std::string value)
{
	for (int i = 0; i < value.length(); i++)
	{
		ASCIICodeGenerator* newHead = new ASCIICodeGenerator;
		newHead->Value = this->GetAsciiValue(value[i]);
		newHead->Next = head;

		head = newHead;
	}

	head = this->GetASCIICodeInOrder(head);

	return head;
}
