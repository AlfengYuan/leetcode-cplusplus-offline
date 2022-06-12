#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {3,2,3};
    Solution solution = Solution();
    int result = solution.majorityElement(nums);
    cout << result << endl;
    return 0;
}