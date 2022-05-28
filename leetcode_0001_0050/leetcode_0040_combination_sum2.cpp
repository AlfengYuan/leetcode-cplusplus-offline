/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> combine;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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

        int cnt = 1;
        while(idx+1 < candidates.size() && candidates[idx] == candidates[idx+1])
        {
            idx++, cnt++;
        }

        for(int i = 0; i<=cnt && target >= i * candidates[idx]; i++)
        {
            dfs(candidates, target - i * candidates[idx], idx+1);
            combine.push_back(candidates[idx]);
        }

        for(int i = 0; i<=cnt && target >= i * candidates[idx]; i++)
        {
            combine.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution solution = Solution();
    vector<vector<int>> res = solution.combinationSum2(candidates, target);
    cout << "[";
    for (vector<int> &num: res)
    {
        cout << "[";
        for(int &i: num)
        {
            cout << i << ", ";
        }
        cout << "], " << endl;
    }
    cout << "]" << endl;
    return 0;
}