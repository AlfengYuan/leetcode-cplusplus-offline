/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        for(int i = 0; i<strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            record[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it = record.begin(); it != record.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution solution = Solution();
    vector<vector<string>> result = solution.groupAnagrams(strs);
    cout << "[";
    for(vector<string> &vecStr: result)
    {
        cout << "[";
        for(string &str: vecStr)
        {
            cout << str << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0; 
}