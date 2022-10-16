class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        heights.push_back(-1);
        for(int i = 0; i<heights.size(); i++)
        {
            while(!stk.empty() && heights[i] < heights[stk.top()])
            {
                int idx = stk.top(); stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                ans = max(ans, (i-left -1) * heights[idx]);
            }
            stk.push(i);
        }

        return ans;
    }
};