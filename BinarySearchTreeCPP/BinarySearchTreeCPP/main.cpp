#include "BinarySearchTree.h"
#include <time.h>

int main()
{
	BinarySearchTree<int> *bst = new BinarySearchTree<int>();
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		bst->insert(rand() % 100);
	}
	
	bst->print();

	delete bst;
	bst = nullptr;

	return 0;
}