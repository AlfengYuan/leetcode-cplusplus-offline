class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i<s.length(); i++){
            if(isalpha(s[i])) str += tolower(s[i]);
            else if(isdigit(s[i])) str += s[i];
        }

        for(int left = 0, right = str.length()-1; left <right; left++, right--){
            if(str[left] != str[right]) return false;
        }

        return true;

    }
};