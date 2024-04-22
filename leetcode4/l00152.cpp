class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpmin(nums.size(), 0);
        vector<int> dpmax(nums.size(), 0);
        dpmin[0] = nums[0];
        dpmax[0] = nums[0];

        for(int i = 1; i<nums.size(); i++){

            dpmax[i] = max(nums[i] * dpmin[i-1], max(nums[i], nums[i] * dpmax[i-1]));
            dpmin[i] = min(nums[i] * dpmax[i-1], min(nums[i] * dpmin[i-1], nums[i]));
        }

        return *max_element(dpmax.begin(), dpmax.end());
    }
};