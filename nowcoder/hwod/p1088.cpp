#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

string str;
int n;

int res = 0;
string path = "";
vector<bool> used;

void dfs(int index){
    if(index == n){
        res++;
        return;
    }

    for(int i = 0; i<str.length(); i++){
        if(used[i]) continue;
        if(i>0 && str[i]==str[i-1] && !used[i-1]) continue;
        if(path.length() > 0 && str[i] == path[path.length()-1]) continue;
        used[i] = true;
        path.push_back(str[i]);
        dfs(index+1);
        path.pop_back();
        used[i] = false;
    }
}

int main(int argc, char *argv[]){
    cin >> str >> n;

    sort(str.begin(), str.end());

    used = vector<bool>(str.length(), false);

    dfs(0);

    cout << res << endl;

    return 0;
}