#include "LinkedList.h"
#include <iostream>
#include <string>
#include <time.h>

template <typename T> void print(LinkedList<T>* list);

int main()
{
	// seed random
	srand((unsigned int)time(NULL));

	// new dynamically allocated linkedlist
	LinkedList<int>* list = new LinkedList<int>();

	// add 10 random numbers between 0-127
	for (int i = 0; i < 10; i++)
	{
		list->insert(rand() % 127);
	}

	// print out list using overloaded operator
	std::cout << *list;

	// delete list and set to null
	delete list;
	list = nullptr;

	return 0;
}

template <typename T>
void print(LinkedList<T>* list)
{
	if (list->getCount() == 0)
	{
		std::cout << "Empty list.\n";
	}
	else
	{
		std::string next = "->";
		for (int i = 0; i < list->getCount(); i++)
		{
			if (i > list->getCount() - 2)
				next = "\n";

			std::cout << list->getDataAtIndex(i) << next;
		}
	}
}