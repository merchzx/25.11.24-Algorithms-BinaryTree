#include "Tree.h"
#include <iostream>
using namespace std;


void Tree::insert(int value, Node*& node)
{
	if (node == nullptr) {
		Node* new_node = new Node(value);
		node = new_node;
	}
	else if (value > node->value) {
		insert(value, node->right);
	}
	else {
		insert(value, node->left);
	}
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

void Tree::Print(Node* node) {
	if (node == nullptr) {
		return;
	}
	Print(node->left);
	cout <<" " << node->value << " ";
	Print(node->right);
}
