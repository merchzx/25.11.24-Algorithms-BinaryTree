#pragma once
#include <iostream>

template <typename T>
class Tree {
    class Node {
    public:
        T value;
        Node* left;
        Node* right;
        Node(T value) : value(value), left(nullptr), right(nullptr) {}
    };
private:
    Node* root;
    void Insert(Node*& node, const T& value);
    void Print(Node* node) const;
    Node* copy(Node* node) const;
    void clear(Node* node);
    void erase(Node*& node, const T& value);
    Node* findMin(Node* node) const;
public:
    Tree() : root(nullptr) {}
    ~Tree();
    Tree(const Tree& other);
    Tree& operator=(const Tree& other);
    void Insert(const T& value);
    void Print() const;
    bool find(const T& value) const;
    void erase(const T& value);
};