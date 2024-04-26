class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26, 0);
        if(s.length() != t.length()) return false;
        for(int i = 0; i<s.length(); i++){
            vec[s[i] - 'a']++;
        }

        for(int i = 0; i<t.length(); i++){
            if(vec[t[i] - 'a'] > 0) vec[t[i] - 'a']--;
            else return false;
        }
        return true;

}
};