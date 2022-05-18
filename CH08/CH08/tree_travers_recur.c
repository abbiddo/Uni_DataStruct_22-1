#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// ���� ��ȸ
void preorder(TreeNode* root) {
	if (!root) return;
	printf("[%d] ", root->data);
	preorder(root->left);
	preorder(root->right);
}

// ���� ��ȸ
void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);  // ���� ���� Ʈ�� ��ȸ
	printf("[%d] ", root->data);  // ��� ������ ���
	inorder(root->right);  // ������ ���� Ʈ�� ��ȸ
}

// ���� ��ȸ
void postorder(TreeNode* root) {
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	printf("[%d] ", root->data);
}

int main() {
	printf("���� ��ȸ : ");
	preorder(root);

	printf("\n���� ��ȸ : ");
	inorder(root);

	printf("\n���� ��ȸ : ");
	postorder(root);
}