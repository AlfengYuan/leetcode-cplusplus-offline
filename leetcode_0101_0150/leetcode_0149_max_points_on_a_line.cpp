/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            unordered_map<string, int> h;
            int cnt = 0;
            for(int j = i+1; j<n; j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                string key = calc(x1, y1, x2, y2);
                h[key]++;
                cnt = max(cnt, h[key]);
            }
            ans = max(ans, cnt+1);
        }
        return ans;

    }

    string calc(int x1, int y1, int x2, int y2)
    {
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        int k = __gcd(dx, dy);
        string key = to_string(dy / k) + "_" + to_string(dx / k);
        if((x1<x2 && y1 > y2) || (x1 > x2 && y1 < y2)) return "_" + key;
        return key;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution solution = Solution();
    int result = solution.maxPoints(points);
    cout << result << endl;
    
    return 0;
}