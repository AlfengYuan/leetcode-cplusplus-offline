class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector<vector<vector<bool>>> f(n+1, vector<vector<bool>>(n+1, vector<bool>(n+1)));
        for(int k = 1; k<=n; k++)
        {
            for(int i = 0; i+k-1 < n; i++)
            {
                for(int j = 0; j+k-1 < n; j++)
                {
                    if(k==1)
                    {
                        f[i][j][k] = s1[i] == s2[j];
                        continue;
                    }

                    for(int u = 1; u < k; u++)
                    {
                        bool o1 = f[i][j][u] && f[i+u][j+u][k-u];
                        bool o2 = f[i][j+k-u][u] && f[i+u][j][k-u];
                        if(o1 || o2)
                        {
                            f[i][j][k] = true;
                            break;
                        }
                    }
                }
                
            }
        }
        return f[0][0][n];
    }
};