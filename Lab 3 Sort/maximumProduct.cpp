int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    
    int maxPos = nums[size-1] * nums[size-2] * nums[size-3];
    int maxWithNeg = nums[0] * nums[1] * nums[size-1];
    return max(maxPos, maxWithNeg);
}
