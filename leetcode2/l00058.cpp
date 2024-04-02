class Solution {
public:
    int lengthOfLastWord(string s) {
        string res;
        string tmp = "";
        s += " ";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' '){
                if(tmp.length() > 0){
                    res = tmp;
                    tmp = "";
                }
            }
            else{
                tmp += s[i];
            }
        }

        return res.length();
    }
};