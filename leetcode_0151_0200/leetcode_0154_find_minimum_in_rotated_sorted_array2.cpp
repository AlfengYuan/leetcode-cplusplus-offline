#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int resultIndex = 0;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] < nums[resultIndex])
            {
                resultIndex = i;
                break;
            }
        }
        return nums[resultIndex];

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2,2,2,0,1};
    Solution solution = Solution();
    int result = solution.findMin(nums);
    cout << result << endl;
    
    return 0;
}