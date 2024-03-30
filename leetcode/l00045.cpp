class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int n = nums.size() - 1;
        vector<int> dp(nums.size(), INT_MAX);
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] >= n - i) dp[i] = 1;
            else {
                if (nums[i] > 0) {
                    int before = INT_MAX;
                    if(i+nums[i] >= n) before = *min_element(dp.begin() + i + 1, dp.end());
                    else before = *min_element(dp.begin() + i + 1, dp.begin() + i + nums[i]+1);
                    if(before < INT_MAX) dp[i] = 1 + before;
                }
            }
        }
        return dp[0];
    }
};