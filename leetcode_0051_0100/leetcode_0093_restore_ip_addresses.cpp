class Solution {
    vector<string> ans;
    vector<int> cur;
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0);
        return ans;
    }

    void dfs(string &s, int idx, int start)
    {
        if(idx==4 && start == s.length())
        {
            string ip = to_string(cur[0]);
            for(int i = 1; i<cur.size(); i++)
            {
                ip += "." + to_string(cur[i]);
            }
            ans.push_back(ip);
            return;
        }

        for(int i = start, num = 0; i<s.length(); i++)
        {
            num = num * 10 + s[i] - '0';
            if(num > 255) break;
            cur.push_back(num);
            dfs(s, idx+1, i+1);
            cur.pop_back();
            if(num==0) break;
        }
    }
};