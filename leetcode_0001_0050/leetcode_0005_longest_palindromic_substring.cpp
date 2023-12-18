class Solution {
public:
    string longestPalindrome(string s) {
        for(int len = s.length(); len > 0; len--)
        {
            for(int left = 0; left <= s.length() - len; left += 1)
            {   
                string str = s.substr(left, len);
                if(IsPalindromic(str)) return str;
            }
        }

        return "";

    }

private:
    bool IsPalindromic(string &s)
    {
        for(int i = 0, j = s.length()-1; i<=j; i++,j--)
        {
            if(s[i] != s[j]) return false;
        }

        return true;
    }

};