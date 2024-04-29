#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

int n;
vector<string> vec;
vector<string> path;
vector<bool> used;
vector<string> res;
void dfs(int cnt){
    if(cnt == n){
        string tmp = "";
        for(string &s: path){
            tmp += s;
        }
        res.push_back(tmp);
        return;
    }

    for(int i = 0; i<vec.size(); i++){
        if(used[i]) continue;
        if(i > 0 && vec[i]==vec[i-1] && !used[i-1]) continue;
        used[i] = true;
        path.push_back(vec[i]);
        dfs(cnt+1);
        path.pop_back();
        used[i] = false;
    }
}


int main(int argc, char *argv[]){
    
    cin >> n;
    
    string c;
    for(int i = 0; i<n;i++){
        cin >> c;
        vec.push_back(c);
    }

    sort(vec.begin(), vec.end());
    used = vector<bool>(vec.size(), false);

    dfs(0);

    //sort(res.begin(), res.end());

    for(string &str: res){
        cout << str << endl;
    }

    return 0;
}