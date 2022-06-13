#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = 1; i<nums.size(); i++)
        {
            result = nums[i] - nums[i-1] > result ? (nums[i] - nums[i-1]) : result;
        }

        return result;

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {3,6,9,1};
    Solution solution = Solution();
    int result = solution.maximumGap(nums);
    cout << result << endl;

    return 0;
}