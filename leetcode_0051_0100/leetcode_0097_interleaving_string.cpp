class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        if(s1.empty()) return s2==s3;
        if(s2.empty()) return s1==s3;
        
        vector<vector<bool>> func(s1.length()+1, vector<bool>(s2.length()+1, false));
        func[0][0] = true;
        for(int i = 0; i<=s1.length(); i++)
        {
            for(int j = 0; j <= s2.length(); j++)
            {
                if(i == 0 && j == 0) func[i][j] = true;
                else if(i == 0)
                {
                    if(func[i][j-1] == true && s2[j-1] == s3[j-1]) func[i][j] = true;
                    else func[i][j] = false;
                }
                else if(j == 0)
                {
                    if(func[i-1][j] == true && s1[i-1]==s3[i-1]) func[i][j] = true;
                    else func[i][j] = false;
                }
                else if(j> 0 && func[i][j-1] == true && s2[j-1] == s3[i+j-1])
                {
                    func[i][j] = true;
                }
                else if(i > 0 && func[i-1][j] == true && s1[i-1] == s3[i+j-1])
                {
                    func[i][j] = true;
                }
                else
                {
                    func[i][j] = false;
                }
            }
        }

        return func[s1.length()][s2.length()];

    }
};