class Solution {
public:
    string reverseWords(string s) {
        stringstream iss(s);
        string tmp;
        vector<string> vec;
        while(getline(iss, tmp, ' ')){
            vec.push_back(tmp);
        }
        string res = "";
        for(int i = vec.size()-1; i>=0; i--){
            string curr = "";
            for(int j = 0; j<vec[i].length(); j++){
                if(vec[i][j] != ' ') curr += vec[i][j];
            }

            if(curr.length() > 0){
                res += curr;
                res += " ";
            }
        }
        res.pop_back();
        return res;

    }
};