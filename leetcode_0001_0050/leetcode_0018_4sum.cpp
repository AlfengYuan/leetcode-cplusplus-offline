#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> Vres;
        if(nums.size() < 4) return Vres;
        set<vector<int>> res;
        vector<int> tmp(4, -1);
        sort(nums.begin(), nums.end(),less<int>());
        for(int l = 0; l<nums.size()-3; ++l)
        {
            if(target >= 0 && nums[l] > target) break;
            for(int i = l+1; i<nums.size()-2; ++i )
            {
                for(int j = i+1, k = nums.size() -1; j < k;)
                {
                    long curSum = (long)nums[l] + (long)nums[i] + (long)nums[j] + (long)nums[k];
                    if(curSum > target)
                    {
                        --k;
                    }
                    else if(curSum < target)
                    {
                        ++j;
                    }
                    else
                    {
                        tmp[0] = nums[l];
                        tmp[1] = nums[i];
                        tmp[2] = nums[j];
                        tmp[3] = nums[k];
                        res.insert(tmp);
                        --k;
                        ++j;
                    }
                }
            }
        }

        Vres.assign(res.begin(), res.end());
        return Vres;

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    int target = 1000000000;
    Solution solution = Solution();
    vector<vector<int>> res  = solution.fourSum(nums, target);
    cout << "[";
    for(vector<int> vecs : res)
    {
        cout << "[";
        for(int vec: vecs)
        {
            cout << vec << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    
    return 0;
}