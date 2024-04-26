class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while(right < nums.size()){
            while(left < nums.size() && nums[left] != 0) left++;
            right = left;
            while(right < nums.size() && nums[right] == 0) right++;
            if(left < nums.size() && right < nums.size()) swap(nums[left], nums[right]); 
        }
    }
};