//BM23 ������ǰ�����
#include <vector>
#include <stdlib.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
};
//void �޷���ֵ
void preOrder(TreeNode* root, vector<int> &res) {	//��Ҫ���������ָ����Ϊ�������ݽ�����Ҳ�ܴ���ȥ
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