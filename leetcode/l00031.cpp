class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> distance(nums.size(), -1);
        for(int i = nums.size()-1; i > 0; i--){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    distance[i] = j;
                    break;
                }
            }
        }

        int left = -1;
        int right = distance.size() - 1;
        for(int i = distance.size() - 1; i >= 0; i--){
            if(distance[i] > left){
                left = distance[i];
                right = i;
            }
        }

        if(left == -1) return reverse(nums.begin(), nums.end());
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        sort(nums.begin() + left + 1, nums.end(), std::less<int>());
    }
};