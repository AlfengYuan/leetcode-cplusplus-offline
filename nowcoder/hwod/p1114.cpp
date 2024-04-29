#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> vec;
vector<vector<int>> board;
vector<vector<bool>> used;
string res = "";
vector<string> path;
int n, x, m;
vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool dfs(int x, int y, int cnt){
    if(cnt == vec.size()){
        string tmp = "";
        for(string &s: path){
            tmp += s + " ";
        }
        if(res.length() == 0 || tmp < res) res = tmp;
        return true;
    }

    if(x < 0 || x >= m || y < 0 || y >= m) return false;
    if(used[x][y]) return false;
    if(board[x][y] != vec[cnt]) return false;

    path.push_back(to_string(x) + " " + to_string(y));
    used[x][y] = true;

    for(auto &v: dir){
        if(dfs(x+v[0], y+v[1], cnt+1)) return true;
    }

    used[x][y] = false;
    path.pop_back();

    return false;
}

int main(int argc, char *argv[]){ 
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x;
        vec.push_back(x);
    }
    cin >> m;

    board = vector<vector<int>>(m, vector<int>(m, 0));
    

    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            cin >> x;
            board[i][j] = x;
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == vec[0]){
                path.clear();
                used = vector<vector<bool>>(m, vector<bool>(m, false));
                if(dfs(i, j, 0)) break;
            }
        }
    }

    if(res.length() <= 0) {
        cout << "error" << endl;
    }else{
        cout << res << endl;
    }

    return 0;
}