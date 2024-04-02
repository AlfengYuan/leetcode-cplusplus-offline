class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
public:
    vector<vector<int>> combine(int n, int k) {
        used = vector<bool>(n+1, false);
        dfs(n, k, 1);

        return res;
    }

    void dfs(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i<=n; i++){
            if(used[i]) continue;
            path.push_back(i);
            used[i] = true;
            dfs(n, k, i+1);
            used[i] = false;
            path.pop_back();
        }
    }
};