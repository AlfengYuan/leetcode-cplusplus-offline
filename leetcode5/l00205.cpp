#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return compare(s, t) && compare(t, s);
    }

    bool compare(string s, string t){
        unordered_map<char, char> mymap;
        if(s.length() != t.length()) return false;
        for(int i = 0; i<s.length(); i++){

            if(mymap.count(s[i]) == 0){
                mymap[s[i]] = t[i];
            }else{
                if(mymap[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};