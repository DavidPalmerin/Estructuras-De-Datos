#include <iostream>
#include <string>


using namespace std;

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

/* Expected type T must be comparable and should implement a ToString() function. */

template <typename T>
class SplayTree
{

	private: 
		class Node
		{
			public:
				T* data;
				Node* left;
				Node* right;
				Node* parent;

				Node(T* data, Node* left, Node* right, Node* parent);
				Node(T* data);
		};

		Node* root;
		int numberOfElements;
		
		/* Implemented */
		Node* createLeaf(T* data);
		void insertBSTPrivate(Node* element, Node* ptr);  // Este se borra al final.
		std::string inOrderPrivate(Node* ptr); // Debugging, se borra al ffinal.
		Node* search(T* key, Node* root); //Tal vez solo dbeug.
		void zig(Node* ptr);
		void zag(Node* ptr);

		/* Implementing */
		void splay(Node* ptr);

		/* ----- To Implement ----- */
		void insertSplay(T* data, Node* ptr);
		void remove(T* data, Node* ptr);

	public:
		SplayTree();
		
		/* Implemented */
		bool isEmpty();
		int getNumberOfElements();
		void inOrder();	          // Solo debugging. Se borra al final.
		void insertBST(T* data);  // Se borra al final.
		void zigTest(T* key); // Solo debug, se be borrar.
		
		/* Implementing */

		/* ----------- To implement -------- */
		void insertSplay(T* data);
		void remove(T* data);

};




#endif