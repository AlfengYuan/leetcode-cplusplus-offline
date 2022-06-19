#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct comp
{
    bool operator() (int a, int b)
    {
        string strA = to_string(a);
        string strB = to_string(b);
        if(strA.length() == strB.length())
        {
            for(int i = 0; i<strA.length(); i++)
            {
                int tmp = (strA[i] - '0') - (strB[i] - '0');
                if(tmp > 0) return true;
                else if(tmp < 0) return false;
                else continue;
            }
            return true;
        }
        else
        {
            for(int i = 0; i<strA.length() + strB.length() -1 ; i++)
            {
                int tmp = (strA[i%strA.length()] - '0') - (strB[i%strB.length()] - '0');
                if(tmp > 0) return true;
                else if(tmp < 0) return false;
                else continue;
            }
            return false;    
        }
    }
};

void mysort(vector<int> &nums, struct comp &comp)
{
    for(int i = 0; i<nums.size()-1; i++)
    {
        for(int j = i+1; j<nums.size(); j++)
        {
            if(comp(nums[j], nums[i]))
            {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
    }
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        struct comp mycomp;
        mysort(nums, mycomp);
        string result = "";
        int i = 0;
        while(i<nums.size())
        {
            if(nums[i] != 0) break;
            i++;
        }

         if(i== nums.size()) return "0";

        for(;i < nums.size(); i++)
        {
            result += to_string(nums[i]);
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution solution = Solution();
    string result = solution.largestNumber(nums);
    cout << "\"" << result << "\"" << endl;

    return 0;

}