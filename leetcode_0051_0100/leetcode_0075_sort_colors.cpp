class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> numColors(3, 0);
        for(int &i:nums)
        {
            numColors[i] += 1;
        }

        int i = 0;
        while(i < numColors[0]) 
        {
            nums[i++] = 0;
        }
        while(i < numColors[0] + numColors[1])
        {
            nums[i++] = 1;
        }
        while(i < nums.size())
        {
            nums[i++] = 2;
        }
    }
};