#pragma once
#include <iostream>

struct Tree {
    int key;
    Tree* left;
    Tree* right;
    unsigned height;
    Tree(int _key) : key(_key), left(nullptr), right(nullptr), height(1) {};
};

class Set {
    Tree* copy(Tree* node) {
        if (node) {
            Tree* new_node = new Tree(node->key);
            new_node->left = copy(node->left);
            new_node->right = copy(node->right);
            return new_node;
        }
        return nullptr;
    }
    Tree* root;
    Tree* _Insert(Tree* root, int key, bool& f);
    Tree* _Erase_elem(Tree* root, int key, bool& f);
    void _Delete_tree(Tree* root);
    void _Print(Tree* root, int step) const;
    unsigned _Height(Tree* root);
    void _Fix_height(Tree* root);
    int _Balance_factor(Tree* root);
    Tree* _Balance(Tree* root);
    Tree* _Rotate_left(Tree* root);
    Tree* _Rotate_right(Tree* root);
    Tree* _Find_min(Tree* root);
    Tree* _Erase_min(Tree* root);
public:
    Set& operator=(const Set& other) {
        if (this != &other) {
            _Delete_tree(root);
            root = copy(other.root);
        }
        return *this;
    }
    Set(const Set& set) {
        root = copy(set.root);
    }
    Set();
    Set(const int& key);
    ~Set();
    void Print() const;
    bool Insert(int key);
    bool Find(int key) const;
    bool Erase(int key);
    Tree* Getroot() {
        return root;
    }
};