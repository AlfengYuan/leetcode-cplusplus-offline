class Solution {
    vector<string> mydict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path = "";
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        dfs(0, path, digits);
        return ans;
    }

    void dfs(int index, string &path, string &digits){
        if(index == digits.length()){
            ans.push_back(path);
            return;
        }

        string curr = mydict[digits[index] - '0'];
        for(int i = 0; i<curr.length(); i++){
            path.push_back(curr[i]);
            dfs(index+1, path, digits);
            path.pop_back();
        }
    }
};