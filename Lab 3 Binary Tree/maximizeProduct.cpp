int calc(BTNode* root, int& ans, int& totalSum) {
    if (root == nullptr) return 0;
    int currSum = calc(root->left, ans, totalSum) + calc(root->right, ans, totalSum) + root->val;
    ans = max(ans, (totalSum - currSum) * currSum);
    return currSum;
}

int maximizeProduct(BTNode* root) {
    int ans = 0;
    int totalSum  = 0;
    totalSum = calc(root, ans, totalSum);
    calc(root, ans, totalSum);
    return ans;
}
