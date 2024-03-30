class Solution {
public:
    string countAndSay(int n) {
        string start = "1";
        for(int i = 1; i<n; i++){
            vector<pair<int, int>> vec = count(start);
            start = say(vec);

        }

        return start;
    }

    vector<pair<int, int>> count(string str){
        vector<pair<int, int>> result;
        for(int i = 0; i<str.length(); i++){
            int count = 1;
            while(i+1 < str.length() && str[i+1] == str[i]){
                count++;
                i++;
            }
            result.push_back(pair<int, int>(count, str[i]-'0'));
        }

        return result;
    }

    string say(vector<pair<int, int>> vec){
        string result = "";
        for(auto &p : vec){
            result += to_string(p.first);
            result += to_string(p.second);
        }
        return result;
    }
};