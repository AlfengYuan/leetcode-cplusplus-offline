#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> vec(nums.size()+1, 0);
        for(int &i: nums)
        {
            if(i >=0 && i <= nums.size()) vec[i] = 1;
        }

        for(int i = 1; i<vec.size(); i++)
        {
            if(vec[i] == 0) return i;
        }
        return vec.size();
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 0};
    Solution solution = Solution();
    int res = solution.firstMissingPositive(nums);
    std::cout << res << std::endl;
    return 0;
}