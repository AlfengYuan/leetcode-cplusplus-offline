#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    Solution solution = Solution();
    vector<int> res = solution.twoSum(nums, 9);
    cout << "[";
    for(size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}