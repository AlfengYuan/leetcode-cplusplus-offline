#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        string tmp = "";
        vector<string> vec;
        int i = 0, j = s.length() - 1;
        while(s[i] == ' ') i++;
        while(s[j] == ' ') j--;
        j++;
        for(; i<=j; i++)
        {
            if(s[i] != ' ') tmp += s[i];
            else
            {
                if(i>0 && s[i] == s[i-1]) continue;
                vec.push_back(tmp);
                tmp = "";
            }

        }
        tmp = "";
        for(int i = vec.size()-1; i>=0; i--)
        {
            if(i > 0) tmp += (vec[i] + " ");
            else tmp += vec[i];
        }

        return tmp;
    }
};

int main(int argc, char *argv[])
{
    string s = "a good   example";
    Solution solution = Solution();
    string result = solution.reverseWords(s);
    cout << "\"" << result << "\"" << endl;
    return 0;
}