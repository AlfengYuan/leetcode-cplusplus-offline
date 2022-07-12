#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, sum = 0;
        int result = numeric_limits<int>::max();
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                result = min(result, right - left + 1);
                sum -= nums[left++];
            }
        }

        return result == numeric_limits<int>::max() ? 0 : result;

    }
};

int main(int argc, char* argv[])
{
    int target = 11; 
    vector<int> nums = { 1, 1, 1, 1, 1, 1, 1, 1 };
    Solution solution = Solution();
    int result = solution.minSubArrayLen(target, nums);
    
    cout << result << endl;

    return 0;
}