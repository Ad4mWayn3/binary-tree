#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>

template <class T>
struct node {
	T value{};
	node* parent{nullptr};
	node* left{nullptr};
	node* right{nullptr};
	node(T _value)
	:	value{_value}
	,	parent{nullptr}
	,	left{nullptr}
	,	right{nullptr}{}

	node(T _value, node _left, node _right)
	:	value{_value}
	,	left{new node<T>{_left}}
	,	right{new node<T>{_right}}{
	}
};

template <class T>
class BTree {
protected:
	node<T>* root{};
	void _destroy(node<T>* root);
	void _bind(node<T>* root);
public:
	~BTree() {
		_destroy(root);
	}
	BTree(node<T>* n) : root{n}{}
	//BTree(node<T> n) : root{n}{}
	BTree(T _value) : root{new node<T>{_value}}{}
	BTree(T _value, node<T> _left, node<T> _right)
	:	root{new node<T>{_value, _left, _right}} {
		_bind(root);
	}
	BTree right() const { return BTree(root->right); }
	BTree left() const { return BTree(root->left); }
	BTree parent() const { return BTree(root->parent); }
	const node<T>* _root() const { return root; }
	T value() const { return root.value; }
	BTree start() const;
	BTree next() const;
};

#endif