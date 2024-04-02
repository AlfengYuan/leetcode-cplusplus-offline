class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        dfs(nums, 0);
        return res;

    }

    void dfs(vector<int>& nums, int index){
        res.push_back(path);
        for(int i = index; i<nums.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
            used[i] = false;
        }
    }
};