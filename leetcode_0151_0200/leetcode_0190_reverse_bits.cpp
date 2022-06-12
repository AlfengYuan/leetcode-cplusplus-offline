#include <iostream>
#include <bitset>
#include <string>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> c(n);
        string s = c.to_string();
        for(int i = 0, j = 31; i<j; i++, j--)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }

        bitset<32> c_reverse(s);
        return c_reverse.to_ulong();

    }
};

int main(int argc, char *argv[])
{
    uint32_t n = 0b00000010100101000001111010011100;
    Solution solution = Solution();
    uint32_t result = solution.reverseBits(n);
    cout << result << " (" << bitset<32>(result).to_string()<< ")" << endl;

    return 0;
}