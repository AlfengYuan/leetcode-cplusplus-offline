class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::less<int>());
        int j = 1;
        for(int &n : nums){
            if(n <= 0) continue;
            else if(n == j){
                j++;
            }else if(n > j){
                return j;
            }
        }

        return j;
    }
};