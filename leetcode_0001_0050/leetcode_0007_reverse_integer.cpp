#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        vector<int> resVec;
        int res = 0;
        int x_copy = x;
        int flag = 1;
        if(x_copy < 0) flag = -1; 
        while(x_copy)
        {
            resVec.push_back((x_copy % 10) * flag);
            x_copy /= 10;
        }
        if(!this->valideInt(resVec, x)) return 0;
        for(int i = 0; i < resVec.size(); ++i)
        {
            res = res * 10 + resVec[i];
        }
        if(x < 0) return res *= -1;
        return res;
    }

private:
    static bool valideInt(const vector<int> vec, int x)
    {
        if(vec.size() > 10)
        {
            return false;
        }
        else if(vec.size() < 10)
        {
            return true;
        }
        else
        {
            vector<int> intMin = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
            if(x < 0) intMin[9] += 1;
            for(int i = 0; i<10; i++)
            {
                if(vec[i] == intMin[i])
                {
                    continue;
                }
                else if(vec[i] < intMin[i])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }
};

int main(int argc, char *argv[])
{
    int x = -2147483648;
    Solution solution = Solution();
    int res = solution.reverse(x);
    std::cout << res << std::endl;
    return 0;
}