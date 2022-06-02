/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, end = 0;
        int ans = 0;
        for(int i = 0; i<nums.size()-1; i++)
        {
            maxPos = max(maxPos, nums[i] + i);
            if(i == end)
            {
                end = maxPos;
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution solution = Solution();
    int result = solution.jump(nums);
    cout << result << endl;
    return 0;
}