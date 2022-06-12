#include <iostream>
#include <map>
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length() <= 2) return s.length();
        map<char, int> mymap;
        int result = -1;
        for(int left = 0, right = 0; right < s.length(); right++)
        {
            if(mymap.find(s[right]) == mymap.end())
            {
                if(mymap.size() < 2) mymap.insert(pair<char, int>(s[right], 1));
                else
                {
                    int tmpSum = 0;
                    for(auto &m: mymap)
                    {
                        tmpSum += m.second;
                    }
                    result = max(result, tmpSum);
                    mymap.insert(pair<char, int>(s[right], 1));
                    while(left < right && mymap.size() > 2)
                    {
                        mymap[s[left]] -= 1;
                        if(mymap[s[left]] == 0) mymap.erase(s[left]);
                        left++;
                    }
                } 
            }
            else
            {
                mymap[s[right]] += 1;
            }
        }

        int tmpSum = 0;
        for(auto &m: mymap)
        {
            tmpSum += m.second;
        }
        result = max(result, tmpSum);

        return result;

    }
};

int main(int argc, char *argv[])
{
    string s = "eceba";
    Solution solution = Solution();
    int result = solution.lengthOfLongestSubstringTwoDistinct(s);
    cout << result << endl;

    return 0;

}