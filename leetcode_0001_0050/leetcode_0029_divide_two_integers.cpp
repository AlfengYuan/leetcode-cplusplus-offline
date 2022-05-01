#include <iostream>
#include <cmath>
using namespace std;
#define MAX_VALUE (pow(2,31)-1)
#define MIN_VALUE (-pow(2,31))
class Solution {
public:
    int divide(int dividend, int divisor) {
        //if(divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if(divisor == -1 && dividend == MIN_VALUE) return MAX_VALUE;
        int sign = 1;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;
        long a = dividend > 0? -(long)dividend: (long)dividend;
        long b = divisor > 0? -(long)divisor: (long)divisor;
        if(a > b) return 0;
        int ans = mydiv(a, b);
        return sign == -1? -ans:ans;
    }

private:
    long mydiv(long a, long b)
    {
        if(a>b) return 0;
        long count = 1;
        long tb = b;
        while(tb+tb >= a && tb+tb < 0)
        {
            tb += tb;
            count += count;
        }
        return count + mydiv(a-tb, b);
    }

};

int main(int argc, char *argv[])
{
    int dividend = 10;
    int divisor = 3;
    Solution solution = Solution();
    int res = solution.divide(dividend, divisor);
    cout << res << endl;
}