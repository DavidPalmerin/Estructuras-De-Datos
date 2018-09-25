#include <iostream>
#include <string>

#include "SplayTree.h"

using namespace std;

/* Constructor for inner class SplayTree::Node */
SplayTree::Node::Node(int data, SplayTree::Node* left, 
	                     SplayTree::Node* right, SplayTree::Node* parent)
{
	this->data = data;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

SplayTree::Node::Node(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

SplayTree::SplayTree()
{
	this->root = NULL;
	this->numberOfElements = 0;
}

/* ------ Implementations of Functions. ------ */

bool SplayTree::is_empty()
{
	return numberOfElements == 0;
}

int SplayTree::size()
{
	return numberOfElements;
}

SplayTree::Node* SplayTree::create_leaf(int data)
{
	return new Node(data);
}

void SplayTree::insert(int data)
{	
	Node* element = create_leaf(data);
	if (root == NULL)
		root = element;
	else
	{
		insert_private(element, root);
		splay(element);
	}
	numberOfElements += 1;
	cout << "After insertion of: " + std::to_string(data) << endl;
	to_string();

}

void SplayTree::insert_private(Node* e, Node* parent)
{	
	if (e->data < parent->data)
	{
		if (parent->left == NULL)
		{
			parent->left = e;
			e->parent = parent;
			return;
		}
		else
			insert_private(e, parent->left);
	}
	else 
	{
		if (parent->right == NULL)
		{
			parent->right = e;
			e->parent = parent;
			return;
		}
		else 
			insert_private(e, parent->right);
	}
}

void SplayTree::to_string()
{
	cout << " Preorder: [" + pre_order(root) + "]" << endl;
}

std::string SplayTree::pre_order(Node* ptr)
{
	std::string currentValue;
	if (ptr == NULL)
		return currentValue;
	
	currentValue = std::to_string(ptr->data);
	std::string left  = pre_order(ptr->left);
	std::string right = pre_order(ptr->right);

	if (left.empty() && right.empty())
		return currentValue;
	
	if (!left.empty() && !right.empty())
		return currentValue + ", " + left + ", " + right;

	if (left.empty())
		return currentValue + ", " + right;
	return currentValue + ", " + left;
}


void SplayTree::zig(Node* ptr)
{
	Node* tmp_node = ptr->right;
	int aux_data = ptr->data;
	
	if (ptr->left != NULL)
	{
		ptr->right = ptr->left;
		ptr->data = ptr->left->data;
		
		ptr->left = ptr->right->left;
		if (ptr->left != NULL)
			ptr->left->parent = ptr;
		
		ptr->right->left = ptr->right->right;
		
		ptr->right->right = tmp_node;
		if (ptr->right->right != NULL)
			ptr->right->right->parent = ptr->right;
		
		ptr->right->data = aux_data;
	}
}

void SplayTree::zag(Node* ptr)
{
	Node* tmp_node = ptr->left;
	int aux_data = ptr->data;
	
	if (ptr->right != NULL)
	{
		ptr->left = ptr->right;
		ptr->data = ptr->right->data;
		
		ptr->right = ptr->left->right;
		if (ptr->right != NULL)
			ptr->right->parent = ptr;

		ptr->left->right = ptr->left->left;
		
		ptr->left->left = tmp_node;
		if (ptr->left->left != NULL)
			ptr->left->left->parent = ptr->left;

		ptr->left->data = aux_data;
	}
}

void SplayTree::search(int key)
{
	Node* node = search_private(key, root);
	if (node == NULL)
		return;
	splay(node);
}

SplayTree::Node* SplayTree::search_private(int key, Node* ptr)
{
	if (ptr == NULL)
		return NULL;
	
	if (ptr->data == key)
		return ptr;

	if (key < ptr->data)
		return search_private(key, ptr->left);
	return search_private(key, ptr->right);
}

void SplayTree::splay(Node* ptr)
{
	if (ptr == root)
		return;

	Node* parent = ptr->parent;
	if (parent == root)
	{
		if (ptr == parent->left)
			zig(parent);
		else
			zag(parent);
		ptr = parent;
		return;
	}

	Node* grandparent = parent->parent;
	if (ptr == parent->left && parent == grandparent->left)
	{
		zig(grandparent);
		zig(grandparent);
	}
	else if (ptr == parent->left && parent == grandparent->right)
	{
		zig(parent);
		zag(grandparent);
	}
	else if (ptr == parent->right && parent == grandparent->left)
	{
		zag(parent);
		zig(grandparent);
	}
	else if (ptr == parent->right && parent == grandparent->right)
	{
		zag(grandparent);
		zag(grandparent);
	}
	
	ptr = grandparent;
	splay(ptr);
}

