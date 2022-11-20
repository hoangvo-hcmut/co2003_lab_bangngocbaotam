int maxNode(BTNode* node) {
    int res = node->val;
    if (node->left) {
        res = max(res, maxNode(node->left));
    }
    if (node->right) {
        res = max(res, maxNode(node->right));
    }
    return res;
}

int greatAncestor(BTNode* root) {
    if (root == nullptr) return 0;
    bool flag = true;
    if (root->left && root->val < maxNode(root->left)) flag = false;
    if (root->right && root->val < maxNode(root->right)) flag = false;
    return (flag ? 1 : 0) + greatAncestor(root->left) + greatAncestor(root->right);
}
