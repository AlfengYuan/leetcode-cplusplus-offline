#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for(int left = 0, right = numbers.size()-1; left< right; )
        {
            if(numbers[left] + numbers[right] == target)
            {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
            else if(numbers[left] + numbers[right] > target) right--;
            else left++;
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution = Solution();
    vector<int> result = solution.twoSum(nums, target);
    cout << "[";
    for(int &i: result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}