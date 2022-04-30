#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();

        vector<int> func = {1};
        for(int i = 1; i<s.length(); i++)
        {
            int j = 1;
            for(;j <= func[i-1]; j++)
            {
                if(s[i] == s[i-j]) break;
            }
            func.push_back(j);
        }
        return *max_element(func.begin(), func.end());
    }
};

int main()
{
    string s = "abadfgghrhrtbrthhd";
    Solution solution = Solution();
    int res = solution.lengthOfLongestSubstring(s);
    cout << res << endl; 
    return 0;
}