//BM28 树的最大深度
//最大深度=树的高度
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
	//上面这条语句会导致超时无法通过测试
	//三目运算符的效率问题：理论上、一般情况下三目运算符比if else更高，但看起来实际上在递归时if else更高效
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