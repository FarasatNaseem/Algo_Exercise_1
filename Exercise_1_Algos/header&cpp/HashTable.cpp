#include "HashTable.h"

int HashTable::GetIndexOfHashTable(unsigned long long hashCode, int arrayLength)
{
	return hashCode % arrayLength;
}

bool HashTable::isIndexEmpty(int index)
{
	if (aktien[index].Name.empty() && aktien[index].K�rzel.empty())
		return true;
	return false;
}

Aktie* HashTable::InsertAtStart(Aktie* aktien, Aktie aktie)
{
	Aktie* newAktie = new Aktie;

	newAktie->Name = new char(aktie.Name.length() + 1);
	newAktie->K�rzel = new char(aktie.K�rzel.length() + 1);

	newAktie->K�rzel = aktie.K�rzel;
	newAktie->Name = aktie.Name;

	newAktie->next = nullptr;

	return newAktie;
}

Aktie* HashTable::InsertAtLast(Aktie* aktien, Aktie aktie)
{
	Aktie* newAktie = new Aktie;

	newAktie->Name = new char(aktie.Name.length() + 1);
	newAktie->K�rzel = new char(aktie.K�rzel.length() + 1);

	Aktie* pointer = aktien;

	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}

	newAktie->K�rzel = aktie.K�rzel;
	newAktie->Name = aktie.Name;

	pointer->next = aktien;
	aktien->next = nullptr;

	return aktien;
}

Aktie* HashTable::AddInList(Aktie* aktien, Aktie aktie)
{
	if (aktien == NULL)
		return InsertAtStart(aktien, aktie);

	return InsertAtLast(aktien, aktie);
}

void HashTable::Add(Aktie& aktie, int index)
{
	if (isIndexEmpty(index))
	{
		aktien[index] = aktie;
	}
	else
	{
		aktien[index].next = AddInList(aktien[index].next, aktie);
	}
}

Aktie HashTable::ReadDetail()
{
	Aktie aktie;

	while (true)
	{
		std::cout << "\nEnter K�rzel: ";
		getline(std::cin, aktie.K�rzel);

		if (!aktie.K�rzel.empty())
		{
			if (aktie.K�rzel.length() > 15)
			{
				std::cout << "Length cannot be greater then 15!!";

				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			std::cout << "This field cannot be empty!!";

			continue;
		}
	}

	while (true)
	{
		std::cout << "\nEnter Name: ";
		getline(std::cin, aktie.Name);

		if (!aktie.Name.empty())
		{
			if (aktie.Name.length() > 15)
			{
				std::cout << "Length cannot be greater then 15!!";

				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			std::cout << "This field cannot be empty!!";

			continue;
		}
	}

	return aktie;
}

int HashTable::GetIndexOfNode(Aktie* head, std::string k�rzel)
{
	int counter = -1;

	for (head; head != NULL; head = head->next)
	{
		counter++;

		if (head->K�rzel == k�rzel)
			break;
	}

	if (head->K�rzel != k�rzel)
		return -1;

	return counter;
}

int HashTable::CountTotalNode(Aktie* head)
{
	Aktie* temp = head;

	int counter = 0;

	for (temp; temp != NULL; temp = temp->next)
	{
		counter++;
	}

	return counter;
}

Aktie HashTable::SearchInListByValue(Aktie* head, std::string k�rzel)
{
	Aktie temp = *head;
	Aktie temp2;

	while (temp.K�rzel != k�rzel && temp.next != NULL)
	{
		temp = *temp.next;
	}

	if (temp.K�rzel != k�rzel)
		return temp2;

	temp2.K�rzel = temp.K�rzel;
	temp2.Name = temp.Name;

	return temp2;
}

Aktie HashTable::Search(std::string k�rzel)
{
	Aktie aktie;

	for (int i = 0; i < 1000; i++)
	{
		if (aktien[i].K�rzel == k�rzel)
		{
			aktie = aktien[i];
			break;
		}
		else
		{
			aktie = SearchInListByValue(aktien[i].next, k�rzel);

			if (!aktie.K�rzel.empty() && !aktie.Name.empty())
			{
				break;
			}

			continue;
		}
	}

	return aktie;
}

Aktie* HashTable::DeleteFirstIndex(Aktie* head)
{
	Aktie* newHead = head->next;

	delete head;

	return newHead;
}

Aktie* HashTable::DeleteLastIndex(Aktie* head)
{
	Aktie* p = head;
	Aktie* q = head->next;

	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}

	p->next = NULL;
	delete q;
	return head;
}

Aktie* HashTable::deleteIndex(Aktie* head, int index)
{
	int totalIndex = CountTotalNode(head);

	if (head == NULL)
	{
		return head;
	}

	Aktie* tempOne = head;
	Aktie* tempTwo = head->next;

	if (index == 0)
	{
		return head = DeleteFirstIndex(head);
	}

	if (index == totalIndex)
	{
		return head = DeleteLastIndex(head);
	}

	for (int i = 0; i < index - 1; i++)
	{
		tempOne = tempOne->next;
		tempTwo = tempTwo->next;
	}

	tempOne->next = tempTwo->next;
	free(tempTwo);

	return head;
}

void HashTable::Delete(std::string k�rzel)
{
	for (int i = 0; i < 1000; i++)
	{

		if (aktien[i].K�rzel == k�rzel)
		{
			aktien[i].K�rzel = "";
			aktien[i].Name = "";

			break;
		}
		else
		{
			int index = GetIndexOfNode(aktien[i].next, k�rzel);

			if (index >= 0)
			{
				deleteIndex(aktien[i].next, index);
				break;
			}
		}
	}
}