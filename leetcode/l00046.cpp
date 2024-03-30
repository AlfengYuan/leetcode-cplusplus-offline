class Solution {
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        dfs(nums, 0, used);

        return ans;
    }

    void dfs(vector<int> &nums, int cnt, vector<bool> &used){
        if(cnt == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, cnt+1, used);
            used[i] = false;
            path.pop_back();
        }

    }
};