class Solution {
    vector<vector<int>> ans;
    vector<int> cur;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }

    void dfs(int start, int n, int k)
    {
        if(k==0)
        {
            ans.push_back(cur);
            return;
        }
        for(int i = start; i<=n; i++)
        {
            cur.push_back(i);
            dfs(i+1, n, k-1);
            cur.pop_back();
        }
    }
};