#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "SplayTree.cpp"

using namespace std;

int main()
{

	srand(time(NULL));

	SplayTree<int> tree;
	std::string s = "[";

	int* r = (int*) malloc(sizeof(int));
	for(int j = 0; j < 5; j++)
	{
		int* k = (int*) malloc(sizeof(int));
		*k = rand() % 25;
		if (j == 3) 
			*r = *k;
		s += std::to_string(*k) + ", ";
		tree.insertBST(k);
	}
	s += "]";

	cout << tree.isEmpty() << endl;
	cout << "Number of elements: " << tree.getNumberOfElements() << endl;
	cout << "Inserted elements: " +  s << endl;
	tree.inOrder();
	cout << "After a zig in: " + std::to_string(*r) << endl;
	tree.zigTest(r);
	tree.inOrder();

	return 0;
}