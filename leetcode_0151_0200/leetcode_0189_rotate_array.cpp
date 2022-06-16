#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k != 0)
        {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k, nums.end());
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution solution = Solution();
    solution.rotate(nums, k);
    cout << "[";
    for(int &i: nums)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}