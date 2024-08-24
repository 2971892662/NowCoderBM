//BM23 二叉树前序遍历
#include <vector>
#include <stdlib.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
};
//void 无返回值
void preOrder(TreeNode* root, vector<int> &res) {	//把要处理的数据指标作为参数传递进来，也能传出去
	if (root != NULL) {
		res.push_back(root->val);	
		preOrder(root->left, res);
		preOrder(root->right, res);
	}
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	preOrder(root, res);
	return res;
}