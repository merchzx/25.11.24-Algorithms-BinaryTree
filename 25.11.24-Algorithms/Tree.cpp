#include "Tree.h"
#include <iostream>
using namespace std;


void Tree::insert(int value, Node*& node)
{
	if (node == nullptr) {
		node = new Node(value);
	}
	else if (value > node->value) {
		insert(value, node->right);
	}
	else if(value<node->value){
		insert(value, node->left);
	}
	else {
		return;
	}
}

bool Tree::find(Node* node, int value) const
{
	if (!node) return false;


	if (value > node->value)
		find(node->right,value);
	else if (value < node->value) 
		find(node->left, value);
	else
	return true;
}

Tree::Tree()
{
	_root = nullptr;
}

void Tree::insert(int value)
{
	insert(value, _root);

}

void Tree::Print()
{
	cout << "Tree v poriadke vozrostaniya"<<endl;
	Print(_root);
	cout << endl;
}

void Tree::erase(int value)
{
	erase(_root, value);
}

bool Tree::find(int value) const
{
	return find(_root, value);
}

void Tree::Print(Node* node) {
	if (node == nullptr) {
		return;
	}
	Print(node->left);
	cout <<" " << node->value << " ";
	Print(node->right);
}

void Tree::erase(Node* node, int value)
{
	if (!node) return;
	if (value > node->value) {
		erase(node->right, value);
	}
	else if (value < node->value) {
		erase(node->left, value);
	}
	else {
		cout << "erase\n";
	}
}
