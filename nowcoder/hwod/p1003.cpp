// https://codefun2000.com/d/hwod/p/P1003
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    int ans = 0;
    string pat;
    cin >> n;
    vector<string> vec;
    vector<int> used(27, 0);
    string tmp;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }

    cin >> pat;

    for(int i = 0; i<pat.length(); i++){
        if(pat[i] == '?') used[26]++;
        else{
            used[pat[i]-'a']++;
        }
    }

    vector<int> comp;
    

    for(int i = 0; i<vec.size(); i++){
        int j = 0;
        comp.assign(used.begin(), used.end());
        for(; j<vec[i].length(); j++){
            if(comp[vec[i][j]-'a'] > 0) comp[vec[i][j]-'a']--;
            else if(comp[26] > 0) comp[26]--;
            else break;
        }

        if(j == vec[i].length()) ans++;
    }

    cout << ans << endl;

    return 0;
}