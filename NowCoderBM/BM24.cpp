//BM24 �������
#include <vector>
#include <stdlib.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left, * right;
};
//void �޷���ֵ
void inOrder(TreeNode* root, vector<int>& res) {	
	if (root != NULL) {
		inOrder(root->left, res);
		res.push_back(root->val);
		inOrder(root->right, res);
	}
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	inOrder(root, res);
	return res;
}