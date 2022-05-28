/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> combine;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }

    void dfs(vector<int> &candidates, int target, int idx)
    {
        if(target == 0)
        {
            ans.push_back(combine);
            return;
        }
        if(idx == candidates.size()) return;
        dfs(candidates, target, idx+1);

        if(target >= candidates[idx])
        {
            combine.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], idx);
            combine.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution solution = Solution();
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    cout << "[";
    for (vector<int> &num: res)
    {
        cout << "[";
        for(int &i: num)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}