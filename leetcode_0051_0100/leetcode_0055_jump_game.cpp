class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0, maxPos=0; i<nums.size(); i++)
        {
            maxPos = max(maxPos, nums[i] + i);
            if(maxPos >= nums.size()-1)
            {
                return true;
            }

            if(i==maxPos && nums[i] == 0) return false;
        }
        return false;
    }
};