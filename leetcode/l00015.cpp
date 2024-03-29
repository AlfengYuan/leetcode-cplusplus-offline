class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size()-2;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            if(nums[i] > 0) break;
            int left = i+1, right = nums.size()-1;
            int target = -nums[i];
            while(left < right){
                if(nums[left] + nums[right] == target){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }else{
                    if(nums[left] + nums[right] > target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }

        return res;
        
    }
};