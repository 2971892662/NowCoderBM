//BM28 ����������
//������=���ĸ߶�
#include <stdlib.h>
struct TreeNode {
	int va;
	TreeNode* left, * right;
};
int height(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	//return height(root->left)>=height(root->right)?height(root->left)+1:height(root->right)+1;
	//�����������ᵼ�³�ʱ�޷�ͨ������
	//��Ŀ�������Ч�����⣺�����ϡ�һ���������Ŀ�������if else���ߣ���������ʵ�����ڵݹ�ʱif else����Ч
	int m = height(root->left) + 1;
	int n = height(root->right) + 1;
	if (m >= n) {
		return m;
	}
	else {
		return n;
	}
}
int maxDepth(TreeNode* root) {
	return height(root);
}