#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1) stack[++top] = p;
}
TreeNode* pop() {
	TreeNode* temp = NULL;
	if (top>-1) temp = stack[top--];
	return temp;
}
void inorder_iter(TreeNode *root){
	while (1) {
		for (; root; root = root->left) push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}
// 실습 : 반복 전위 순회
void preorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) { 
			printf("[%d] ", root->data);
			push(root);
		}
		root = pop();
		if (!root) break;
		root = root->right;
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main() {
	printf("전위 순휘 : ");
	preorder_iter(root);

	printf("\n중위 순휘 : ");
	inorder_iter(root);
}