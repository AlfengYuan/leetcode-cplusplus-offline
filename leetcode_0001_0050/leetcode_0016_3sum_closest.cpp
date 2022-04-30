#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        if(nums.size() == 3) return res;
        int minAbs = abs(res - target);
        sort(nums.begin(), nums.end(),less<int>());
        for(int i = 0; i<nums.size()-2; ++i )
        {
            for(int j = i+1, k = nums.size() -1; j < k;)
            {
                int curSum = nums[i] + nums[j] + nums[k];
                if(abs(curSum - target) < minAbs)
                {
                    res = curSum;
                    minAbs = abs(curSum - target);
                }

                if(curSum > target)
                {
                    --k;
                }
                else if(curSum < target)
                {
                    ++j;
                }
                else
                {
                    return target;
                }
            }
        }

        return res;

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution solution = Solution();
    int res = solution.threeSumClosest(nums, 1);
    cout << res << endl;
}