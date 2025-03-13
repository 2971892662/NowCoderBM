//BM36 Æ½ºâ¶þ²æÊ÷ÅÐ¶Ï
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool flag = true;
int THeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = THeight(root->left) + 1;
    int right = THeight(root->right) + 1;
    if (left - right < -1 || left - right>1) {
        flag = false;
    }
    if (left >= right) {
        return left;
    }
    else {
        return right;
    }
}
bool IsBalanced_Solution(TreeNode* pRoot) {
    THeight(pRoot);
    return flag;
}