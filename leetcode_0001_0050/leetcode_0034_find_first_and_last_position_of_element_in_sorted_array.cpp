#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        for(int i = 0; i<nums.size(); ++i)
        {
            if(nums[i] == target)
            {
                res[0] = i;
                break;
            }
        }

        for(int j = nums.size()-1; j>=0; --j)
        {
            if(nums[j] == target)
            {
                res[1] = j;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution solution = Solution();
    vector<int> res = solution.searchRange(nums, target);
    cout << "[";
    for(int &i : res)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}