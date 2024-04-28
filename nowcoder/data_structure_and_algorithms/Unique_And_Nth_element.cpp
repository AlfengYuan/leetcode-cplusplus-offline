class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::greater());
        vector<int>::iterator pos = unique(nums.begin(), nums.end());
	    nums.erase(pos, nums.end());
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size()==1) return nums[0];
        nth_element(nums.begin(), nums.begin()+2, nums.end(),std::greater());
        return nums[2];
    }
};
