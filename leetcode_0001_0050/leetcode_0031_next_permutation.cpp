/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k =nums.size() -1;
        while(k > 0 && nums[k-1] >= nums[k]) k--;

        if(k <= 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int t = nums.size() - 1;
            while(nums[t] <= nums[k-1]) t--;

            swap(nums[t], nums[k-1]);
            reverse(nums.begin()+k, nums.end());
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution();
    solution.nextPermutation(nums);
    cout << "[";
    for(int &i:nums)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}