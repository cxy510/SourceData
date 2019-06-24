#pragma once
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
template <typename Key,typename Value>
class BST {  //二分搜索树
private:
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;
		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
		Node(Node *node) {
			this->key =node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};
	Node *root;
	int count;
public:
	BST() {
		root = NULL;
		count = 0;
	}
	~BST() {
		destory(root);
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	void insert(Key key, Value value) {
		root=intsert(root, key, value);
	}
	bool contain(Key key) {
		return contain(root, key);
	}
	Value *serach(Key key) {
		return search(root, key);
	}
	void preOrder() {//前序遍历
		preOrder(root);
	}
	void inOrder() {//中序遍历
		inOrder(root);
	}
	void postOrder() {//后续遍历
		postOrder(root);
	}

	//层序遍历
	void levelOrder() {
		queue<Node*>q;
		q.push(root);
		while (!q.empty()) {
			Node *node = q.front();
			q.pop();
			cout << node->key << endl;
			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}
	}

	//寻找最小键值
	Key minimum() {
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
	}
	//寻找最大键值
	Key minimum() {
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}
	//删除最小值所在的节点
	void removeMin() {
		if (root) {
			root = removeMin(root);
		}
	}
	//删除最大值所在的节点
	void removeMax() {
		if (root) {
			root = removeMax(root);
		}
	}
	//从二叉树中删除键值为key的节点
	void remove(Key key) {  
		root = remove(root, key);
	}
private:
	Node *insert(Node*node, Key key, Value value) {
		if (node == NULL) {
			count++;
			return new Node(key, value);
		}
		if (key == node->key) {
			node->value = value;
		}
		else if (key < node->key) {
			node->left = insert(node->left, key, value);
		}
		else {
			node->right = insert(node->right, key, value);
		}
		return node;
	}
	//以node为根的二叉搜索树中是否包含键值为key的节点
	bool contain(Node *root, Key key) {
		if (node == NULL) {
			return false;
		}
		if (key == node->key) {
			return true;
		}
		else if (key < node->key) {
			return contain(node->left, key);
		}
		else {
			return contain(node->right, key);
		}

	}
	//在以node为根的二叉搜索树中查找key所对应的value
	Value * search(Node* node, Key key) {
		if (node == NULL) {
			return NULL;
		}
		if (key == node->key) {
			return &(node->value);
		}
		else if (key < node->key) {
			return search(node->left, key);
		}
		else{
			return search(node->right, key);
		}
	}
    void preOrder(Node* node) {   
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(Node *root) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	void postOrder(Node *root) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	void destory(Node *node) {
		if (node != NULL) {
			destory(node->left);
			destory(node->right);
			delete node;
			count--;
		}
	}
	Node* minimum(Node *node) {
		if (node->left == NULL) {
			return node;
		}
		return minimum(node->left);
	}
	Node* maximum(Node *node) {
		if (node->right == NULL) {
			return node;
		}
		return maximum(node->right);
	}
	Node *removeMin(Node * node) {
		if (node->left == NULL) {
			Node *rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left=removeMin(node->left);
		return node;
	}
	Node *removeMax(Node * node) {
		if (node->right == NULL) {
			Node *leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		node->right = removeMin(node->right);
		return node;
	}
	Node *remove(Node *node, Key key) {
		if (node == NULL) {
			return NULL;
		}
		if (key < node->key) {
			node->left=remove(node->left, key);
			return node;
		}
		else if (key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else {//key==node->key
			if (node->left == NULL) {
				Node*rightnode = node->right;
				delete node;
				count--;
				return rightnode;
			}
			if (node->right == NULL) {
				Node*leftnode = node->left;
				delete node;
				count--;
				return leftnode;
			}
		
			Node *successor = new Node(minimum(node->right));
			count++;
			successor->right = removeMin(node->right);
			successor->left = node->left;
			delete node;
			count--;
			return successor;
		}

	}
};
