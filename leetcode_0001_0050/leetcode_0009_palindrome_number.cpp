class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        return IsPalindromicString(to_string(x));


    }

private:
    static bool IsPalindromicString(const string s)
    {
        for(int i = 0, j = s.length()-1; i<=j; i++,j--)
        {
            if(s[i] != s[j]) return false;
        }

        return true;
    }
};