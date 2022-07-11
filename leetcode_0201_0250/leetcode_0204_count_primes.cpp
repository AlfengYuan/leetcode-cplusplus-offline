#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        if (n <= 1) return 0;
        isPrime[1] = false;
        isPrime[0] = false;
        for (int i = 2; i * i < n; i++)
        {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }

        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (isPrime[i]) count++;
        }
        return count;

    }
};

int main(int argc, char* argv[])
{
    int n = 10;
    Solution solution = Solution();
    int result = solution.countPrimes(n);
    cout << result << endl;
    return 0;
}