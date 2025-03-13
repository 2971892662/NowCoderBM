//BM32 合并二叉树
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* merge(TreeNode*& t1, TreeNode*& t2) { //得传指针型引用，才能改变指针的指向
    if (t1 != nullptr && t2 != nullptr) {
        t1->val = t1->val + t2->val;
        merge(t1->left, t2->left);
        merge(t1->right, t2->right);
        return t1;
    }
    if (t1 == nullptr && t2 == nullptr) {
        return nullptr;
    }
    if (t1 != nullptr && t2 == nullptr) {
        return t1;
    }
    if (t1 == nullptr && t2 != nullptr) {
        t1 = t2;
        return t1;
    }
    return nullptr;
}
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    return merge(t1, t2);
}