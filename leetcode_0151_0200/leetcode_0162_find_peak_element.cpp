#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > nums[result]) result = i;
        }
        return result;

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,1};
    Solution solution = Solution();
    int result = solution.findPeakElement(nums);
    cout << result << endl;
    return 0;
}