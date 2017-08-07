#pragma once
#include <vector>

template<class T>
struct Node {
	int key_value;
	T data;
	Node<T>* left;
	Node<T>* right;
};

template<class T>
class btree
{
public:
	btree();
	~btree();

	std::vector<Node<T>*> getLeafs();
	std::vector<Node<T>*> getLevel(int level);

	void insert(int key);
	void insert(int key, T data);
	Node<T>* search(int key);
	void destroy_tree();

private:

	std::vector<Node<T>*> * getLeafs(Node<T>* leaf, std::vector<Node<T>*> * queue);
	std::vector<Node<T>*> * getLevel(Node<T>* leaf, int level, std::vector<Node<T>*> * queue);

	void destroy_tree(Node<T>* leaf);

	void insert(int key, Node<T>* leaf);
	void insert(int key, T data, Node<T>* leaf);

	Node<T>* search(int key, Node<T>* leaf);

	Node<T>* root;
};

