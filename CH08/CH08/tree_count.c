#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int get_node_count(TreeNode* node) {
	int cnt = 0;

	if (node) cnt = 1 + get_node_count(node->left) + get_node_count(node->right);
	return cnt;
}

int get_leaf_count(TreeNode* node) {
	int cnt = 0;

	if (node) {
		if (!node->left && !node->right) return 1;
		else cnt = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return cnt;
}

int get_height(TreeNode* node) {
	int height = 0;
	if (node) height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

// 실습
int get_deg2_count(TreeNode* node) {
	int cnt = 0, tmp = 0;

	if (node) {
		if (node->left && node->right) tmp = 1;
		cnt = tmp + get_deg2_count(node->left) + get_deg2_count(node->right);
	}
	return cnt;
}

int main() {
	TreeNode n4 = { 200, NULL, NULL };
	TreeNode n5 = { 500, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("노드의 개수 : %d\n", get_node_count(&n1));
	printf("단말 노드의 개수 : %d\n", get_leaf_count(&n1));
	printf("트리의 높이 : %d\n", get_height(&n1));
	printf("차수가 2인 노드의 개수 : %d\n", get_deg2_count(&n1));
}