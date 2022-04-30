#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = -1;
        int left = 0, right = height.size()-1;
        while(left <= right)
        {
            int currArea = (right - left) * min(height[left], height[right]);
            if(currArea > res) res = currArea;
            if(height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }

        }

        return res;

    }
};

int main(int argc, char *argv[])
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution = Solution();
    int res = solution.maxArea(height);
    cout << res << endl;
    return 0;
}