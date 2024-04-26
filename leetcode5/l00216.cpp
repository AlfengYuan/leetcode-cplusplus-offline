#include <vector>
#include <iostream>

using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<bool> used;
    vector<int> path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return combinationSum(candidates, n, k);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int k) {
        //sort(candidates.begin(), candidates.end());
        used = vector<bool>(candidates.size(), false);
        dfs(candidates, target, 0, 0, k);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int sum, int index, int k){
        if(sum > target) return;
        if(sum == target && path.size() == k){
            ans.push_back(path);
            return;
        }

        for(int i = index; i<candidates.size() && sum+candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue;
            if(used[i]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            dfs(candidates, target, sum, i, k);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }
};