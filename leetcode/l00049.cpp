class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> mymap;
        for(string str: strs){
            string curr(str);
            sort(curr.begin(), curr.end()); 
            auto iter = mymap.find(curr);
            if(iter == mymap.end()){
                vector<string> tmpvec {str};
                mymap[curr] = tmpvec;
            }
            else{
                mymap[curr].push_back(str);
            }
        }

        for(auto iter = mymap.begin(); iter != mymap.end(); iter++){
            result.push_back(iter->second);
        }

        return result;

    }
};