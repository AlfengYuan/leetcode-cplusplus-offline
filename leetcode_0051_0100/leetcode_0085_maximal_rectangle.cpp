class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> heights(n);
        int ans = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, maxArea(heights));
        }
        return ans;
    }

    int maxArea(vector<int> &heights)
    {
        stack<int> stk;
        int ans = 0;
        heights.push_back(-1);
        for(int i = 0; i<heights.size(); i++)
        {
            while(!stk.empty() && heights[i] < heights[stk.top()])
            {
                int idx = stk.top(); stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                ans = max(ans, (i-left-1) * heights[idx]);
            }
            stk.push(i);
        }
        heights.pop_back();
        return ans;
    }
};