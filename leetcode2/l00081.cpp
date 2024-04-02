class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lr = 0, rl = nums.size()-1;
        while(lr < rl && nums[lr] <= nums[lr+1]) lr++;
        while(lr < rl && nums[rl] >= nums[rl-1]) rl--;
    

        if(nums[0] <= target && nums[lr] >= target) return binarySearch(nums, target, 0, lr);
        else if(nums[rl]<=target && nums[nums.size()-1] >= target) return binarySearch(nums, target, rl, nums.size()-1);
        else return false;
    }

    bool binarySearch(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = left + ((right - left) / 2);
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) {
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return false;

    }
};