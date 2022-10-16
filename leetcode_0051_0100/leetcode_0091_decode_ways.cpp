#include <cassert>
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        s = ' ' + s;
        vector<int> f(3);
        f[0] = 1;
        for(int i = 1; i<=n; i++)
        {
            f[i%3] = 0;
            int a = s[i] - '0', b = (s[i-1] - '0') * 10 + a;
            if (a>=1 && a <=9) f[i%3] += f[(i-1)%3];
            if (b >= 10 && b <= 26) f[i%3] += f[(i-2) %3];
        }
        return f[n%3];
    }
};