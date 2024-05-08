#include <vector>
#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

int n;
vector<vector<int>> board;
vector<bool> infect;
int orginInfect = 0;
int ans = 0;

class UnionFind{
public:
    vector<int> ids;
    UnionFind(int n){
        for(int i = 0; i<n; i++){
            ids.push_back(i);
        }
    }

    int find(int key){
        return ids[key];
    }

    bool unionKey(int x, int y){
        int x_id = find(x);
        int y_id = find(y);
        if(x_id == y_id) return false;

        for(int i = 0; i<ids.size(); i++){
            if(ids[i] == y_id){
                ids[i] = x_id;
            }
        }

        return true;
    }

    bool is_connected(int x, int y){
        return find(x)==find(y);
    }
};

int main(int argc, char *argv[]){

    string input, tmp;
    getline(cin, input);
    n = atol(input.c_str());
    infect = vector<bool>(n, false);
    getline(cin, input);
    stringstream ss(input);
    while(getline(ss, tmp, ',')){
        infect[atol(tmp.c_str())] = true;
        orginInfect++;
    }

    for(int i = 0; i<n; i++){
        getline(cin, input);
        stringstream ss2(input);
        vector<int> curr;
        while(getline(ss2, tmp, ',')){
            curr.push_back(atol(tmp.c_str()));
        }
        board.push_back(curr);
        curr.clear();
    }

    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 1) board[j][i] = 1;
        }
    }

    UnionFind uf(n);
    for(int i = 0; i<board.size(); i++){
        for(int j = i+1; j<board[i].size(); j++){
            if(board[i][j] == 1){
                if(!uf.is_connected(i, j)){
                    uf.unionKey(i, j);
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(infect[i]){
            infect[uf.ids[i]] = true;
        }
    }

    for(int i = 0; i<n; i++){
        if(infect[uf.ids[i]]) ans++;
    }

    cout << ans-orginInfect << endl;

    return 0;
}