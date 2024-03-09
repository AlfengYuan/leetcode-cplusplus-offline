class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        for(int len = s.length(); len > 0; len--){
            if(len > 128) continue;
            for(int start = 0; start<=s.length() - len; start++){
                string curr = s.substr(start, len);
                if(check(curr)) return len;
            }
        }

        return 0;

    }

    bool check(string &s){
        vector<int> vec(129, 0);
        for(int i = 0; i<s.length(); i++){
            if(vec[s[i]] > 0) return false;
            vec[s[i]]++;
        }
        return true;
    }
};