#include <iostream>
#include <string>


using namespace std;

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

/* Expected type T must be comparable and should implement a ToString() function. */

class SplayTree
{

	private: 
		class Node
		{
			public:
				int data;
				Node* left;
				Node* right;
				Node* parent;

				Node(int data, Node* left, Node* right, Node* parent);
				Node(int data);
		};

		Node* root;
		int numberOfElements;
		
		/* Implemented */
		Node* create_leaf(int data);
		void insert_private(Node* element, Node* ptr);  // Este se borra al final.
		std::string pre_order(Node* ptr); // Debugging, se borra al ffinal.
		Node* search_private(int key, Node* root); //Tal vez solo dbeug.
		void zig(Node* ptr);
		void zag(Node* ptr);
		void splay(Node* ptr);

		/* Implementing */

		/* ----- To Implement ----- */
		void remove(int data, Node* ptr);

	public:
		SplayTree();
		
		/* Implemented */
		bool is_empty();
		int size();
		void to_string();	          // Solo debugging. Se borra al final.
		void insert(int data);  // Se borra al final.
		
		/* Implementing */
		void search(int key);  // Creo que debe de subir el más cercano a key (si key no está).

		/* ----------- To implement -------- */
		void remove(int data);

};




#endif