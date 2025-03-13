//BM38 二叉树中最近公共祖先
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool dfs(TreeNode* root, int tar, vector<int>& path) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == tar) {
        path.push_back(root->val);
        return true;
    }
    bool a = dfs(root->left, tar, path);
    bool b = dfs(root->right, tar, path);
    if (a || b == true) {
        path.push_back(root->val);
    }
    return a || b;
}
int lowestCommonAncestor38(TreeNode* root, int o1, int o2) {
    vector<int> a(0);
    vector<int> b(0);
    dfs(root, o1, a);
    dfs(root, o2, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0;
    while (1) {
        if (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
            continue;
        }
        return a[i - 1];
    }
}