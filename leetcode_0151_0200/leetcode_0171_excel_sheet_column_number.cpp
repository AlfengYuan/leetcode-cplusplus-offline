#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(int i = 0; i<columnTitle.length(); i++)
        {
            result *= 26;
            result += columnTitle[i] - 64;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    string columnTitle = "AA";
    Solution solution = Solution();
    int result = solution.titleToNumber(columnTitle);
    cout << result << endl;

    return 0;
}