#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (!node) return node;
	if (key == node->data) return node;
	else 	if (key < node->data) return search(node->left, key);
	else return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* root, int key) {
	if (!root) return new_node(key);

	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	return root;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left) current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (!root) return root;
	if (key < root->data) root->left = delete_node(root->left, key);
	else if (key > root->data) root->right = delete_node(root->right, key);
	else {
		if (!root->left) {
			TreeNode* temp = root->right;
			return temp;
		}
		else if (!root->right) {
			TreeNode* temp = root->left;
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

int main() {
	TreeNode* root = NULL;
	TreeNode* temp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 \n");
	inorder(root);
	printf("\n\n");

	if (search(root, 30)) printf("발견");
	else printf("실패");
}