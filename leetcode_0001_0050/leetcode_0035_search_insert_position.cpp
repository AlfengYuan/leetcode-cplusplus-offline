#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); ++i)
        {
            if(target <= nums[i]) return i;
        }
        return nums.size();

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution solution = Solution();
    int res = solution.searchInsert(nums, target);
    std::cout << res << std::endl;
    return 0;
}