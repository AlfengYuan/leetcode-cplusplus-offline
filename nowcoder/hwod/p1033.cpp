#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    string s;
    cin >> s;
    string tmp(s);
    sort(tmp.begin(), tmp.end());
    int i = 0;
    for(; i<tmp.length(); i++){
        if(tmp[i] != s[i]) break;
    }

    if(i!=s.length()){
        int j = s.length()-1;
        for(; j>=0; j--){
            if(s[j] == tmp[i]) break;
        }
        swap(s[i], s[j]);
    }

    cout << s << endl;

    return 0;
}