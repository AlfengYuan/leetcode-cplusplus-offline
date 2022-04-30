#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Vres;
        if(nums.size() < 3) return Vres;
        set<vector<int>> res;
        vector<int> tmp(3, -1);
        sort(nums.begin(), nums.end(),less<int>());
        for(int i = 0; i<nums.size()-2; ++i )
        {
            for(int j = i+1, k = nums.size() -1; j < k;)
            {
                int curSum = nums[i] + nums[j] + nums[k];
                if(curSum > 0)
                {
                    --k;
                }
                else if(curSum < 0)
                {
                    ++j;
                }
                else
                {
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[k];
                    res.insert(tmp);
                    --k;
                    ++j;
                }
            }
        }

        Vres.assign(res.begin(), res.end());

        return Vres;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution = Solution();
    vector<vector<int>> res = solution.threeSum(nums);
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