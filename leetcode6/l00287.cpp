class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int maxN = *max_element(nums.begin(), nums.end());
        vector<int> vec(maxN+1, 0);
        for(int &num: nums){
            vec[num]++;
            if(vec[num] > 1) return num;
        }

        return -1;

    }
};