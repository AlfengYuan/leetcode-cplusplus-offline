#include <bitset>
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> c(n);
        return c.count();
    }
};

int main(int argc, char *argv[])
{
    uint32_t n = 0b00000000000000000000000000001011;
    Solution solution = Solution();
    int result = solution.hammingWeight(n);
    cout << result << endl;

    return 0;
}