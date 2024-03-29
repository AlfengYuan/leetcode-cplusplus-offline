class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < abs(res - target)){
                    res = sum;
                    if(res == target) return res;
                    //while(left < right && nums[left] == nums[left+1]) left++;
                    //while(left < right && nums[right] == nums[right-1]) right--;
                    //left++;
                    //right--;
                }
                    
                if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return res;

    }
};