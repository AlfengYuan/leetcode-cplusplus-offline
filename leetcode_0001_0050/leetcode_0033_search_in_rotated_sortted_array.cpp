#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); ++i)
        {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution solution = Solution();
    int res = solution.search(nums, target);
    cout << res << endl;
    return 0;
}