#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int start = 0;
        while(start < nums.size())
        {
            while(start < nums.size() && nums[start] == val) start++;
            if(start == nums.size()) return res;
            nums[res++] = nums[start++];
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution solution = Solution();
    int res = solution.removeElement(nums, val);
    cout << "[";
    for(int i = 0; i<res; i++)
    {
        cout << nums[i] << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}