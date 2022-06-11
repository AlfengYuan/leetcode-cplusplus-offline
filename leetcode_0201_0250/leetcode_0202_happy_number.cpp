#include <string>
#include <map>
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        map<string, int> myMap;
        while(1)
        {
            long tmp  = 0;
            for(char &c: s)
            {
                tmp += pow(c-'0', 2);
            }
            s = to_string(tmp);
            if(myMap.count(s)) return false;
            if(s=="1") return true;
            else myMap.insert(pair<string,int>(s, 1));
        }
        return false;

    }
};

int main(int argc, char *argv[])
{
    int n = 7;
    Solution solution = Solution();
    bool result = solution.isHappy(n);
    if(result) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;

}
