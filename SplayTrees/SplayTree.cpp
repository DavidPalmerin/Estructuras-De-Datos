#include <iostream>
#include <string>

#include "SplayTree.h"

using namespace std;

/* Constructor for inner class SplayTree::Node */
template <typename T>
SplayTree<T>::Node::Node(T* data, SplayTree::Node* left, 
	                     SplayTree::Node* right, SplayTree::Node* parent)
{
	this->data = data;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

template <typename T>
SplayTree<T>::Node::Node(T* data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

template <typename T>
SplayTree<T>::SplayTree()
{
	this->root = NULL;
	this->numberOfElements = 0;
}

/* ------ Implementations of Functions. ------ */

template <typename T>
bool SplayTree<T>::isEmpty()
{
	return root == NULL;
}

template <typename T>
int SplayTree<T>::getNumberOfElements()
{
	return numberOfElements;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::createLeaf(T* data)
{
	return new Node(data);
}

template <typename T>
void SplayTree<T>::insertBST(T* data)
{
	if (data == NULL)
		return;
	
	Node* element = createLeaf(data);
	if (root == NULL)
		root = element;
	else 
		insertBSTPrivate(element, root);
	numberOfElements += 1;
}

template <typename T>
void SplayTree<T>::insertBSTPrivate(Node* e, Node* parent)
{	
	if (*e->data <= *parent->data)
	{
		if (parent->left == NULL)
		{
			parent->left = e;
			e->parent = parent;
			return;
		}
		else
			insertBSTPrivate(e, parent->left);
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
			insertBSTPrivate(e, parent->right);
	}
}

template <typename T>
void SplayTree<T>::inOrder()
{
	cout << "[" + inOrderPrivate(root) + "]" << endl;
}

template <typename T>
std::string SplayTree<T>::inOrderPrivate(Node* ptr)
{
	std::string currentValue;
	if (ptr == NULL)
		return currentValue;
	
	currentValue = std::to_string(*ptr->data);
	std::string left  = inOrderPrivate(ptr->left);
	std::string right = inOrderPrivate(ptr->right);

	if (left.empty() && right.empty())
		return currentValue;
	
	if (!left.empty() && !right.empty())
		return currentValue + ", " + left + ", " + right;

	if (left.empty())
		return currentValue + ", " + right;
	return currentValue + ", " + left;
}


template <typename T>
void SplayTree<T>::zig(Node* ptr)
{
	if (ptr == NULL || ptr == root)
		return;

	Node* parent = ptr->parent;
	if (ptr != parent->left)
		return;

	parent->left = ptr->right;
	if (ptr->right != NULL)
		ptr->right->parent = parent;
	
	ptr->parent = parent->parent;
	if (parent->parent != NULL)
	{
		if (parent->parent->left == parent)
			parent->parent->left = ptr;
		else // if (parent->parent->right == parent)
			parent->parent->right = ptr;
	}

	parent->parent = ptr;
	ptr->right = parent;
	if(root == parent)
		root = ptr;
	cout << "zig!" << endl;
}

template <typename T>
void SplayTree<T>::zag(Node* ptr)
{
	if (ptr == NULL || ptr == root)
		return;

	Node* parent = ptr->parent;
	if (ptr != parent->right)
		return;

	parent->right = ptr->left;
	if (ptr->left != NULL)
		ptr->left->parent = parent;

	ptr->parent = parent->parent;
	if (parent->parent != NULL)
	{
		if (parent->parent->left == parent)
			parent->parent->left = ptr;
		else 
			parent->parent->right = ptr;
	}

	parent->parent = ptr;
	ptr->left = parent;
	if (root == parent)
		root = ptr;
	cout << "zag!" << endl;
}

template <typename T>
void SplayTree<T>::zigTest(T* key)
{

	Node* pivot = search(key, root);
	if (pivot == NULL) 
		return;
	cout << "Se hara zig!" << endl;
	zag(pivot);
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::search(T* key, Node* ptr)
{
	if (ptr == NULL)
		return NULL;
	
	if (*ptr->data == *key)
		return ptr;

	if (*key <= *ptr->data)
		return search(key, ptr->left);
	return search(key, ptr->right);
}


