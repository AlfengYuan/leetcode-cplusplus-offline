class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int minN = nums[0]-1;
       int res = 0;
       for(int i = 0; i<nums.size(); i++){
            int j = i;
            while(j < nums.size() && nums[j] == nums[i] && j - i < 2) j++;
            if(j==nums.size()) break;
            if(nums[j] != nums[i]){
                i = j - 1;
            } else{
                while(j < nums.size() && nums[j] == nums[i]){
                    res++;
                    nums[j] = minN;
                    j++;
                }
                i = j-1;
            }
       }

       for(int i = 0; i<nums.size(); i++){
            if(nums[i] != minN) continue;
            int j = i+1;
            while(j < nums.size() && nums[j] == minN) j++;
            if(j == nums.size()) break;
            else{
                swap(nums[i], nums[j]);
            }
       }

       return nums.size() - res;
    }
};