class Solution {
public:
    bool isMatch(string s, string p) {
        s = ' ' + s;
        p = ' ' + p;
        vector<vector<bool>> f(s.length(), vector<bool>(p.length(), false));
        f[0][0] = true;

        for(int i = 0; i<s.length(); i++){
            for(int j = 1; j<p.length(); j++){
                if(p[j] != '*'){
                    f[i][j] = i && j && f[i-1][j-1] && (s[i]==p[j] || p[j]=='?');
                }else{
                    f[i][j] = (i && f[i-1][j]) || (j && f[i][j-1]);
                }
            }
        }

        return f[s.length()-1][p.length()-1];
    }
};