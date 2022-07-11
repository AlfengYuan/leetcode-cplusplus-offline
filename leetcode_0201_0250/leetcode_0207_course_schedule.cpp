#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        map<int, vector<int>> Graph;
        for (int i = 0; i < numCourses; i++)
        {
            Graph[i] = {};
        }
        vector<int> degree(numCourses, 0);
        stack<int> mystack;
        for (vector<int> &vec : prerequisites)
        {
            Graph[vec[1]].push_back(vec[0]);
            degree[vec[0]] += 1;
        }

        for (int i = 0; i < degree.size(); i++)
        {
            if (degree[i] == 0) mystack.push(i);
        }

        int count = 0;
        while (!mystack.empty())
        {
            int v = mystack.top(); mystack.pop();
            count++;
            for (int &i : Graph[v])
            {
                degree[i]--;
                if (degree[i] == 0)
                {
                    mystack.push(i);
                }
            }
        }

        if (count == numCourses) return true;
        return false;
    }
};

int main(int argc, char* argv[])
{
    int numCourses = 2; 
    vector<vector<int>> prerequisties = { {1, 0}, {0, 1} };
    Solution solution = Solution();
    bool result = solution.canFinish(numCourses, prerequisties);
    if (result) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}