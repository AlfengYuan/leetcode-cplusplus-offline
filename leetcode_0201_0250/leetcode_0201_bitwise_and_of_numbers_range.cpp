#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        int right_limit = right, bit = getBitLen(left);
        if (bit < 31) right_limit = pow(2, bit);
        int result = -1;
        for (int i = left; i <= min(right_limit, right); i++)
        {
            result &= i;
            if (i == pow(2, 31) - 1) break;
        }
        return result;
    }

    int getBitLen(int num)
    {
        if (num == 0) return 1;
        int i = 0;
        while (num)
        {
            num >>= 1;
            i++;
        }
        return i;
    }
};

int main(int argc, char* argv[])
{
    int left = 5, right = 7;
    Solution solution = Solution();
    int result = solution.rangeBitwiseAnd(left, right);
    cout << result << endl;
    return 0;
}