#include <map>
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, char> sMap;
        map<char, char> tMap;
        for(int i = 0; i<s.length(); i++)
        {
            if(sMap.count(s[i]) || tMap.count(t[i]))
            {
                if((t[i] != sMap[s[i]]) || (s[i] != tMap[t[i]])) return false;
            }
            else
            {
                sMap.insert(pair<char, char>(s[i], t[i]));
                tMap.insert(pair<char, char>(t[i], s[i]));
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    string s = "badc";
    string t = "baba";
    Solution solution = Solution();
    bool result = solution.isIsomorphic(s, t);
    if(result) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}