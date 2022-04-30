#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0) return 0;
        int res = 1;
        int start = 1;
        while(start < nums.size())
        {
            while(start < nums.size() && nums[start] == nums[start-1]) start++;
            if(start == nums.size()) return res;
            nums[res++] = nums[start++];
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 1, 2};
    Solution solution = Solution();
    int res = solution.removeDuplicates(nums);
    cout << "[";
    for(int i = 0; i<res; i++)
    {
        cout << nums[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}