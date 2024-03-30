class Solution {
    vector<vector<int>> ans;
    vector<bool> used;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        used = vector<bool>(candidates.size(), false);
        dfs(candidates, target, 0, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int sum, int index){
        if(sum > target) return;
        if(sum == target){
            ans.push_back(path);
            return;
        }

        for(int i = index; i<candidates.size() && sum+candidates[i] <= target; i++){
            //if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            //used[i] = true;
            dfs(candidates, target, sum, i);
            //used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }
};