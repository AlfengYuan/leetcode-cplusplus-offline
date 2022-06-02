/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> combine;
    vector<bool> used;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;

    }

    void dfs(vector<int> &nums, int idx)
    {
        if(idx == nums.size())
        {
            ans.push_back(combine);
            return;
        }

        for(int i = 0; i<nums.size(); i++)
        {
            if(!used[i])
            {
                combine.push_back(nums[i]);
                used[i] = true;
                dfs(nums, idx+1);
                used[i] = false;
                combine.pop_back();
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution();
    vector<vector<int>> result = solution.permute(nums);
    cout << "[";
    for(vector<int> &res: result)
    {
        cout << "[";
        for(int &i : res)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}