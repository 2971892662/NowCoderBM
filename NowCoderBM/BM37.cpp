//BM37 二叉搜索树最近公共祖先
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int lowestCommonAncestor37(TreeNode* root, int p, int q) {
    vector<int> a(0);
    vector<int> b(0);
    TreeNode* temp = root;
    while (temp->val != p) {
        a.push_back(temp->val);
        if (p < temp->val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    a.push_back(temp->val);
    temp = root;
    while (temp->val != q) {
        b.push_back(temp->val);
        if (q < temp->val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    b.push_back(temp->val);
    int i = 0;
    while (true) {
        if (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
            continue;
        }
        return a[i - 1];
    }
}