//BM33 二叉树的镜像

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* Mirror33(TreeNode* pRoot) {
    if (pRoot != nullptr) { //是if不是while
        TreeNode* m_temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = m_temp;
        Mirror33(pRoot->left);
        Mirror33(pRoot->right);
    }
    return pRoot;
}