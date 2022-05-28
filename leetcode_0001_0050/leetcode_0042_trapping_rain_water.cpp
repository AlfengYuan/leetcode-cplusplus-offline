/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0, ans = 0;
        while(l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax)
            {
                ans += lmax - height[l];
                l++;
            }
            else
            {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution = Solution();
    int result = solution.trap(height);
    cout << result << endl;
    return 0;
}