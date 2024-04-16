class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(i && nums[i] == nums[i-1]) continue;
            if(i < nums.size()-1 && nums[i]==nums[i+1]) continue;
            return nums[i];
        }

        return -1;
    }
};