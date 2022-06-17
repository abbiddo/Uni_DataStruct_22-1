#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
	int key;
	struct AVLNode* left, *right;
}AVLNode;

int get_height(AVLNode* node) {
	int height = 0;
	if (node) height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(AVLNode* node) {
	if (!node) return 0;

	return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key) {
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

AVLNode* rotate_right(AVLNode* parent) {
	AVLNode* child = parent->left;
	parent->left = NULL;
	child->right = parent;
	return child;
}
AVLNode* rotate_left(AVLNode* parent) {
	AVLNode* child = parent->right;
	parent->right = NULL;
	child->left = parent;
	return child;
}

AVLNode* insert(AVLNode* node, int key) {
	if (!node) return(create_node(key));

	if (key < node->key) node->left = insert(node->left, key);
	else if (key > node->key) node->right = insert(node->right, key);
	else return node;

	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key) return rotate_right(node);
	if (balance < - 1 && key > node->right->key) return rotate_left(node);
	if (balance > 1 && key > node->left->key) {
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}

	return node;
}

void preorder(AVLNode* root) {
	if (root) {
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	AVLNode* root = NULL;
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 3);
	//root = insert(root, 0);

	preorder(root);
}