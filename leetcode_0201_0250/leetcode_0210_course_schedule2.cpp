#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
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
        vector<int> result;
        while (!mystack.empty())
        {
            int v = mystack.top(); mystack.pop();
            result.push_back(v);
            for (int &i : Graph[v])
            {
                degree[i]--;
                if (degree[i] == 0)
                {
                    mystack.push(i);
                }
            }
        }

        if (result.size() == numCourses) return result;
        return vector<int>({});

    }
};

int main(int argc, char* argv[])
{
    int numCourses = 4;
    vector<vector<int>> prerequisties = { {1, 0}, {2, 0},{3, 1}, {3, 2} };
    Solution solution = Solution();
    vector<int> result = solution.findOrder(numCourses, prerequisties);
    
    cout << "[";
    for (int &i : result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}