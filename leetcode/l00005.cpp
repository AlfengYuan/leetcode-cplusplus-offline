class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            int l = i-1, r = i+1;
            while(l>=0 && r < s.length() && s[l]==s[r]) l--, r++;
            if(r-l-1 > ans.length()) ans = s.substr(l+1, r-l-1);

            l = i, r = i+1;
            while(l>=0 && r < s.length() && s[l]==s[r]) l--, r++;
            if(r-l-1 > ans.length()) ans = s.substr(l+1, r-l-1);
        }

        return ans;
    }
};