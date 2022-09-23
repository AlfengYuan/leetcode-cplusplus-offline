class Solution {
public:
    bool isNumber(string s) {
        vector<bool> flag(3, false);  //['+/-', '.', 'e/E']
        if(s==".") return false;
        if(s[0] == '.') flag[1] = true;
        if(isalpha(s[0]) && tolower(s[0]) != 'e') return false;
        if(tolower(s[0])=='e' ||tolower(s[s.length()-1])=='e') return false;
        if(s[0] == '+' || s[0] == '-')
        {
            if(s.length() <= 1) return false;
            flag[0] = true;
        }
        for(int i = 1; i<s.length(); i++)
        {
            if(isdigit(s[i])) continue;
            else if(tolower(s[i])=='e')
            {
                if(i==1 && (s[i-1]=='.' || s[i-1]=='+' || s[i-1]=='-')) return false;
                else if(flag[2] == true) return false;
                else flag[2] = true;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if(tolower(s[i-1])!='e') return false;
                else if(i == s.length()-1) return false;

            }
            else if(s[i] == '.')
            {
                if(flag[1] == true || flag[2] == true) return false;
                else if(flag[0])
                {
                    if((i==s.length()-1)&&(s[i-1] == '-' || s[i-1] == '+')) return false;
                }
                flag[1] = true;
            }
            else if(isalpha(s[i]))
            {
                return false;
            }

        }
        return true;
    }
};