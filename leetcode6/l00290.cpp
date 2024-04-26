class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        stringstream iss(s);
        string tmp = "";
        while(iss >> tmp){
            vec.push_back(tmp);
        }

        if(vec.size() != pattern.length()) return false;

        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        for(int i = 0; i<pattern.length(); i++){
            if(ps.count(pattern[i]) == 0 && sp.count(vec[i]) == 0){
                ps[pattern[i]] = vec[i];
                sp[vec[i]] = pattern[i];
            }else if(ps.count(pattern[i]) > 0 && sp.count(vec[i]) > 0){
                if(ps[pattern[i]] != vec[i] || sp[vec[i]] != pattern[i]){
                    return false;
                }
            }else{
                return false;
            }
        }

        return true;

    }
};