#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <sstream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = Stringsplit(version1, '.');
        vector<int> ver2 = Stringsplit(version2, '.');
        if(ver1.size() > ver2.size())
        {
            for(int i = 0; i<ver1.size(); i++)
            {
                if(i < ver2.size())
                {
                    if(ver1[i] > ver2[i]) return 1;
                    else if(ver1[i] < ver2[i]) return -1;
                    else continue;
                }
                else
                {
                    if(ver1[i] > 0) return 1;
                    else continue;
                }
            }
        }
        else if(ver1.size() <= ver2.size())
        {
            for(int i = 0; i<ver2.size(); i++)
            {
                if(i<ver1.size())
                {
                    if(ver1[i] > ver2[i]) return 1;
                    else if(ver1[i] < ver2[i]) return -1;
                    else continue;
                }
                else
                {
                    if(ver2[i] > 0) return -1;
                    else continue;
                }
            }
        }

        
        return 0;
    }

    vector<int> Stringsplit(string str,const char split)
    {
        vector<int> result;
        istringstream iss(str);	// 输入流
        string token;			// 接收缓冲区
        while (getline(iss, token, split))	// 以split为分隔符
        {
            result.push_back(atoi(token.c_str()));
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    string version1 = "1.01";
    string version2 = "1.001";
    Solution solution = Solution();
    int result = solution.compareVersion(version1, version2);
    cout << result << endl;
    
    return 0;
}