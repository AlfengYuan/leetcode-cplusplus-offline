/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        for(int i = 1; i<=n; i++)
        {
            fact[i] = fact[i-1] * i;
        }

        string ans;
        vector<bool> used(n+1);
        for(int i = 0; i<n; i++)
        {
            int cnt = fact[n-i-1];
            for(int j = 1; j<=n; j++)
            {
                if(used[j]) continue;
                if(k > cnt) k-=cnt;
                else
                {
                    ans += j+'0';
                    used[j] = true;
                    break;
                }
            }
        }

        return ans;

    }
};