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
	Tree* root;
	Tree* _Insert(Tree* root, int key);
	Tree* _Erase_elem(Tree* root, int key);
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
	Tree* copy(Tree* node);
public:
	Set();
	Set(const Set& set);
	~Set();
	void Print() const;
	bool Insert(int key);
	bool Find(int key) const;
	bool Erase(int key);
	Tree* Get_Root();
	Set& operator=(const Set& other);
};