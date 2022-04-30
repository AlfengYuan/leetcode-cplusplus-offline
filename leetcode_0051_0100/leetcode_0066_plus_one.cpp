#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        for(int i = digits.size()-1; i>=0; --i)
        {
            if(add == 0) break;
            int sum = digits[i] + add;
            digits[i] = sum % 10;
            add = sum / 10;
        }

        if(add > 0) digits.insert(digits.begin(), add);

        return digits;
    }
};

int main(int argc, char *argv[])
{
    vector<int> digits = {1, 2, 3};
    Solution solution = Solution();
    vector<int> res = solution.plusOne(digits);
    cout << "[";
    for(int &i: res)
    {
        cout << i << ", ";
    }
    cout << "]";
    return 0;
}