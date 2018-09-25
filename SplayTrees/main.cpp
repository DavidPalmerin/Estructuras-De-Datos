#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "SplayTree.cpp"

using namespace std;

int main()
{

	srand(time(NULL));

	SplayTree tree;
	std::string s = "[";
	int r;
	for(int j = 0; j < 10; j++)
	{
		int k = rand() % 25;
		if (j == 2) 
			r = k;
		s += std::to_string(k) + ", ";
		tree.insert(k);
	}

	s += "]";

	cout << "Elements to insert: " + s << endl;
	cout << "Number of elements: " << tree.size() << endl;
	tree.to_string();
	cout << "After searching " + std::to_string(r) << endl;
	tree.search(r);
	tree.to_string();

	cout << "contador: " + std::to_string(c) << endl;

	return 0;
}