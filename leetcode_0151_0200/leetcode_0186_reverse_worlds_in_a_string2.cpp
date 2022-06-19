#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void reverseWords(vector<char>& s) {
        for(int left = 0, right = s.size() - 1; left < right; ++left, --right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }
        s.push_back(' ');
        for(int idx = 0; idx < s.size(); )
        {
            int space = idx;
            while(s[space++] != ' ');
            for(int left = idx, right = space-2; left < right; ++left, --right)
            {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
            }
            idx = space;
        }

        s.pop_back();
    }
};

int main(int argc, char *argv[])
{
    vector<char> s = {'t','h','e',' ', 's', 'k', 'y',' ','i','s',' ','b','l','u','e'};
    Solution solution = Solution();
    solution.reverseWords(s);

    cout << "[";
    for(char &c:s)
    {
        cout << "\"" << c << "\"" << ", ";
    }
    cout << "]" << endl;

    return 0;
}