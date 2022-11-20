bool calc(BTNode* curr, int a, int b, int *res) {
    if (curr == nullptr) return false;
    int left = calc(curr-> left, a, b, res) ? 1 : 0;
    int right = calc(curr->right, a, b, res) ? 1 : 0;
    // curr node is a or b
    int mid = (curr->val == a || curr->val == b) ? 1 : 0;
    if (mid + left + right >= 2) {
        // any of two flags left, right, mid are true
        // it is result
        *res = curr->val;
    }
    // true if one of conditions matches
    return (mid + left + right > 0);
}

int lowestAncestor(BTNode* root, int a, int b) {
    int ans = 0;
    calc(root, a, b, &ans);
    return ans;
}
