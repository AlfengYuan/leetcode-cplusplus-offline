#include <iostream>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0 ) N = -N;
        double ans = 1.0;
        while(N)
        {
            if(N & 1) ans *= x;
            x *= x;
            N >>= 1;
        }
        return n < 0 ? 1/ans:ans;
    }
};

/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
int main(int argc, char *argv[])
{
    double x = 2.00000;
    int n = 10;
    Solution solution = Solution();
    double result = solution.myPow(x, n);
    cout << result << endl;
    return 0;
}