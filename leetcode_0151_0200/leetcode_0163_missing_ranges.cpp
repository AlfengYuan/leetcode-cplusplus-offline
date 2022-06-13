#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        vector<int> tmp(2, -1);
        string str;
        if(nums.size() < 1)
        {
            tmp[0] = lower;
            tmp[1] = upper;
            if(tmp[0] == tmp[1]) str = to_string(tmp[0]);
            else str = to_string(tmp[0]) + "->" + to_string(tmp[1]);
            result.push_back(str);
            return result;
        }
        if(nums[0] > lower)
        {
            tmp[0] = lower;
            tmp[1] = nums[0] - 1;
            if(tmp[0] == tmp[1]) str = to_string(tmp[0]);
            else str = to_string(tmp[0]) + "->" + to_string(tmp[1]);
            result.push_back(str);
        }

        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] - nums[i-1] == 1) continue;
            else
            {
                tmp[0] = nums[i-1] + 1;
                tmp[1] = nums[i] - 1;
                if(tmp[0] == tmp[1]) str = to_string(tmp[0]);
                else str = to_string(tmp[0]) + "->" + to_string(tmp[1]);
                result.push_back(str);
            }
        }

        if(nums[nums.size()-1] < upper)
        {
            tmp[0] = nums[nums.size()-1] + 1;
            tmp[1] = upper;
            if(tmp[0] == tmp[1]) str = to_string(tmp[0]);
            else str = to_string(tmp[0]) + "->" + to_string(tmp[1]);
            result.push_back(str);
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {0,1,3,50,75};
    int lower = 0, upper = 99;
    Solution solution = Solution();
    vector<string> result = solution.findMissingRanges(nums, lower, upper);
    cout << "[";
    for(string &s: result)
    {
        cout << "\"" << s << "\""<< ", ";
    }
    cout << "]" << endl;
    return 0;
}