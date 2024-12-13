#include "Tree.h"

template <typename T>
void Tree<T>::Insert(Node*& node, const T& value) {
    if (!node) {
        node = new Node(value);
        return;
    }
    if (value < node->value) Insert(node->left, value);
    else if (value > node->value) Insert(node->right, value);
}

template <typename T>
bool Tree<T>::find(const T& value) const {
    Node* current = root;
    while (current) {
        if (value == current->value) return true;
        if (value < current->value) current = current->left;
        else current = current->right;
    }
    return false;
}

template <typename T>
void Tree<T>::Print(Node* node) const {
    if (!node) return;
    Print(node->left);
    std::cout << node->value << " ";
    Print(node->right);
}

template <typename T>
void Tree<T>::Print() const {
    Print(root);
    std::cout << std::endl;
}

template <typename T>
typename Tree<T>::Node* Tree<T>::copy(Node* node) const {
    if (!node) return nullptr;
    Node* newNode = new Node(node->value);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

template <typename T>
Tree<T>::Tree(const Tree& other) : root(nullptr) {
    root = copy(other.root);
}

template <typename T>
void Tree<T>::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template <typename T>
Tree<T>::~Tree() {
    clear(root);
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree& other) {
    if (this == &other) return *this;
    clear(root);
    root = copy(other.root);
    return *this;
}

template <typename T>
typename Tree<T>::Node* Tree<T>::findMin(Node* node) const {
    while (node->left) node = node->left;
    return node;
}

template <typename T>
void Tree<T>::erase(Node*& node, const T& value) {
    if (!node) return;
    if (value < node->value) erase(node->left, value);
    else if (value > node->value) erase(node->right, value);
    else {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        }
        else if (!node->left) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (!node->right) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* minNode = findMin(node->right);
            node->value = minNode->value;
            erase(node->right, minNode->value);
        }
    }
}

template <typename T>
void Tree<T>::erase(const T& value) {
    erase(root, value);
}

template <typename T>
void Tree<T>::Insert(const T& value) {
    Insert(root, value);
};