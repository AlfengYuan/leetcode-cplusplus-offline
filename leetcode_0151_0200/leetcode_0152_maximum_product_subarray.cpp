#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int originSize = nums.size();
        if(originSize <= 1) return nums[0];

        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); )
        {
            if(*iter == 1) iter = nums.erase(iter);
            else iter++;
        }

        if(nums.size() < originSize) nums.push_back(1);

        vector<vector<int>> func(nums.size(), vector<int>(nums.size(), 0));

        int result = nums[0];
        for(int i = 0; i<nums.size(); i++)
        {
            func[i][i] = nums[i];
            if(func[i][i] > result) result = func[i][i];
        }

        for(int i = 0; i<nums.size()-1; i++)
        {
            for(int j = i+1 ; j<nums.size(); j++)
            {
                func[i][j] = func[i][j-1] * func[j][j];
                if(func[i][j] > result) result = func[i][j];
                if(func[j][j] == 0) break;
            }
        }

        return result;

    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2,3,-2,4};
    Solution solution = Solution();
    int result = solution.maxProduct(nums);
    cout << result << endl;
    return 0;
}