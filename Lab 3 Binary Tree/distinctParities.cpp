int getSum(BTNode* root) {
    if (root == nullptr) return 0;
    return root->val + getSum(root->left) + getSum(root->right);
}

int distinctParities(BTNode* root) {
    if (root == nullptr) return 0;
    bool hasTwoChildren = root->left != nullptr && root->right != nullptr;
    int sumLeft = getSum(root->left);
    int sumRight = getSum(root->right);
    bool isOddEven = abs(sumLeft % 2) != abs(sumRight % 2);
    return ((hasTwoChildren && isOddEven) ? 1 : 0) + distinctParities(root->left) + distinctParities(root->right);
}
