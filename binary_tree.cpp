#include "binary_tree.hpp"
#include <iostream>

template <class T>
void BTree<T>::_destroy(node<T>* root) {
	if (root->right != nullptr)
		_destroy(root->right);
	if (root->left != nullptr)
		_destroy(root->left);
	delete root;
	root = nullptr;
}

template <class T>
void BTree<T>::_bind(node<T>* root) {
	if (root->left != nullptr) {
		root->left->parent = root;
		_bind(root->left);
	}
	if (root->right != nullptr) {
		root->right->parent = root;
		_bind(root->right);
	}
}

template <class T>
BTree<T> BTree<T>::start() const{
	for (node<T>* i=root;;i=i->left)
		if (i->left == nullptr)
			return BTree(i);
}

template <class T>
BTree<T> BTree<T>::next() const{
	puts("next: start");
	if (root->right != nullptr) {
		puts("next: case a");
		return BTree<T>(root->right).start();
	}
	for (node<T>* i = root;;i=i->parent) {
		puts("next: loop");
		std::cerr << i << ' ' << i->parent->left << '\n';
		if (i->parent == nullptr) {
			std::cerr << "next: case c\n";
			return BTree<T>(nullptr);
		}
		if (i == i->parent->left) {
			std::cerr << "next: case b\n";
			return BTree<T>(i->parent);
		}
	}
}

int main() {
	BTree<int> a
	{1,
		{2,
			{3, 4, 5},
			{6, 7, 8}
		},
		{9,
			{10, 11, 12},
			{13, 14, 15}
		}
	};

	//auto ptr{a.start().next().next()._root()};

	std::cout << a._root()->left->left->right << '\n'
		<< a.start().next().next()._root();
}