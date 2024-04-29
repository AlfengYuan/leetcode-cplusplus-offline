#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
bool check(string &key, string &pat){
    if(pat.length() > key.length()) return false;
    for(int i = 0; i<pat.length(); i++){
        if(pat[i] != key[i]) return false;
    }

    return true;
}
int main(int argc, char *argv[]){
    string input;
    string pat;
    getline(cin, input);
    getline(cin, pat);


    unordered_map<string, bool> mymap;
    vector<string> res;
    for(int i = 0; i<input.length(); i++){
        if(isalpha(input[i])){
            int j = i;
            while(j<input.length() && isalpha(input[j])) j++;
            string curr = input.substr(i, j-i);
            if(mymap.count(curr) == 0 && check(curr, pat))
            {
                mymap[curr] = true;
            }
            i = j;
        }
    }

    for(auto &v: mymap){
        string key = v.first;
        res.push_back(key);
    }

    if(res.size() == 0) res.push_back(pat);

    for(string &s: res){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}