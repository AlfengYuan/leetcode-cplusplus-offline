class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size()-3;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            if(nums[i] >= 0 && nums[i] > target) break;
            for(int j = i+1; j<nums.size()-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = nums.size()-1;
                long long comp = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(left < right){
                    if( (long long)nums[left] + (long long)nums[right] == comp){
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else{
                        if((long long)nums[left] + (long long)nums[right] > comp){
                            right--;
                        }else{
                            left++;
                        }
                    }
                }
            }
        }

        return res;

    }

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