#include <iostream>
#include <string>


using namespace std;

#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayTree
{
	public:
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

		SplayTree();
		
		bool is_empty();
		int size();
		int get_root_data();
		void to_string();	          

		void insert(int data);  
		Node* search(int key); 
		void remove(int data);

	private: 
		Node* root;
		int number_of_elements;
		
		Node* create_leaf(int data);
		std::string pre_order(Node* ptr); 
		Node* successor(Node* ptr); 
		Node* subtree_smaller(Node* ptr);

		void zig(Node* ptr);
		void zag(Node* ptr);
		void splay(Node* ptr);

		void insert_private(Node* element, Node* ptr); 
		Node* search_private(int key, Node* root, Node* closer); 

};

#endif