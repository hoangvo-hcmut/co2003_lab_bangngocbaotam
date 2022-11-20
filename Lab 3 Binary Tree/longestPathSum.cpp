void calc(BTNode* root, int sum, int len, int& maxLen, int& maxSum) {
    // reached leaf
    if (root == nullptr) {
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum) {
            maxSum = sum;
        }
        return;
    }
    calc(root->left, sum + root->val, len + 1, maxLen, maxSum);
    calc(root->right, sum + root->val, len + 1, maxLen, maxSum);
}

int longestPathSum(BTNode* root) {
    int maxSum = root->val, maxLen = 0;
    calc(root, 0, 0, maxLen, maxSum);
    return maxSum;
}
