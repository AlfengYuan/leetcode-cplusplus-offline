class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        for(int j = 0; j < strs[0].length(); j++)
        {
            for(int i = 1; i < strs.size(); i++){
                if(j < strs[i].length() && strs[i][j] == strs[0][j]) continue;
                else return result;
            }
            result += strs[0][j];
        }

        return result;

    }
};