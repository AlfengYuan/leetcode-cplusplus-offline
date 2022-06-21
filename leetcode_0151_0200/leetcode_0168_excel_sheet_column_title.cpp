#include<iostream>
#include <string>
#include <vector>
using namespace std;
 
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber)
        {
            columnNumber -= 1;
            char tmp = toascii(columnNumber % 26 + 65);
            result = tmp + result;
            columnNumber /= 26;
        }
        return result;

    }
};
int main()
{
	int columnNumber = 701;
	Solution solution = Solution();
	string result = solution.convertToTitle(columnNumber);
	cout << result << endl;
	return 0;
}