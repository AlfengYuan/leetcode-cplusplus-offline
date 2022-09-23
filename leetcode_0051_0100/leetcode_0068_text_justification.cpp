/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans, cur;
        for(int i = 0, curWidth = 0; i < words.size(); i++)
        {
            if(words[i].length() + curWidth + cur.size() <= maxWidth)
            {
                curWidth += words[i].length();
                cur.push_back(words[i]);
            }
            else
            {
                ans.push_back(fillSpace(cur, maxWidth, false));
                cur = vector<string>{words[i]};
                curWidth = words[i].length();
            }
        }
        ans.push_back(fillSpace(cur, maxWidth, true));
        return ans;
    }

    string fillSpace(vector<string>& words, int maxWidth, bool last)
    {
        int curWidth = 0;
        for(int i = 0; i<words.size(); i++)
        {
            if(i != words.size()-1) words[i] += ' ';
            curWidth += words[i].length();
        }

        if(last || words.size() == 1)
        {
            words[words.size()-1] += string(maxWidth - curWidth, ' ');
        }
        else
        {
            for(int i = 0; curWidth++ < maxWidth; i = (i+1)%(words.size()-1))
            {
                words[i] += ' ';
            }
        }

        string ans;
        for(int i = 0; i<words.size(); i++) ans += words[i];
        return ans;
    }
};