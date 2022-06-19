#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int unbounded = 0, bounded = nums[0], result = bounded;
        for(int i = 1; i<nums.size(); i++)
        {
            int tmp = unbounded + nums[i];
            unbounded = max(unbounded, bounded);
            bounded = tmp;
            result = max(result, max(unbounded, bounded));
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 1, 1, 2};
    Solution solution = Solution();
    int result = solution.rob(nums);
    cout << result << endl;

    return 0;
}