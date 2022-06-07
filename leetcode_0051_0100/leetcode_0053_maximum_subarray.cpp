#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int preMax = nums[0], preMin = nums[0];
        for(int i = 1; i<nums.size(); i++)
        {
            int a = preMax + nums[i], b = preMin + nums[i];
            preMax = max(nums[i], max(a, b));
            preMin = min(nums[i], min(a, b));
            ans = max(ans, preMax);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution = Solution();
    int result = solution.maxSubArray(nums);
    cout << result << endl;
    return 0;
}