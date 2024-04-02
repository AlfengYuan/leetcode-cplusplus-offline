#include <sstream>
#include <string>
#include <vector>
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string tmp;
        vector<string> vec;
        while(getline(ss, tmp, '/')){
            if(tmp == "" || tmp == ".") continue;
            else if(tmp == ".."){
                if(vec.size() > 0) vec.pop_back();
            }
            else vec.push_back(tmp);
        }

        string res = "/";
        for(string &s: vec){
            res += s;
            res += '/';
        }

        if(res.length() > 1) res.pop_back();

        return res;
    }
};