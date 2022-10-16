class Solution {
    vector<vector<int>> ans;
    vector<int> subset;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int> &nums, int idx)
    {
        if(idx == nums.size())
        {
            ans.push_back(subset);
            return;
        }

        int k = idx + 1;
        while(k < nums.size() && nums[k] == nums[idx]) k++;
        for(int i = 0; i<=k-idx; i++)
        {
            dfs(nums, k);
            subset.push_back(nums[idx]);
        }

        for(int i = 0; i<=k-idx; i++)
        {
            subset.pop_back();
        }
    }
};