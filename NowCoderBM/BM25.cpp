//BM24 �������
#include <vector>
#include <stdlib.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left, * right;
};
//void �޷���ֵ
void postOrder(TreeNode* root, vector<int>& res) {	
	if (root != NULL) {
		postOrder(root->left, res);
		postOrder(root->right, res);
		res.push_back(root->val);
	}
}
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;
	postOrder(root, res);
	return res;
}