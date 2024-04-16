#include <vector>
#include <iostream>

using namespace std;

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

class SolutionDfs {
    vector<bool> used;
    int province = 0;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        used = vector<bool>(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i++) {
            if (!used[i]) {
                dfs(isConnected, i);
                province++;
            }
        }

        return province;

    }

    void dfs(vector<vector<int>>& isConnected, int index) {
        for (int i = 0; i < isConnected[index].size(); i++) {
            if (isConnected[index][i] == 1) {
                if (used[i]) continue;
                used[i] = true;
                dfs(isConnected, i);
            }
        }
    }
};

class SolutionUnion {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        UnionFind uf(isConnected.size());
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = i+1; j<isConnected[i].size(); j++){
                if(isConnected[i][j]){
                    if(!uf.is_connected(i, j)){
                        uf.unionKey(i, j);
                    }
                }
            }
        }

        for(int i = 0; i<uf.ids.size(); i++){
            if(uf.ids[i] == i) ans++;
        }

        return ans;
    }
};

class SolutionLeetcode {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> parent(cities);
        for (int i = 0; i < cities; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < cities; i++) {
            for (int j = i + 1; j < cities; j++) {
                if (isConnected[i][j] == 1) {
                    Union(parent, i, j);
                }
            }
        }
        int provinces = 0;
        for (int i = 0; i < cities; i++) {
            if (parent[i] == i) {
                provinces++;
            }
        }
        return provinces;
    }
};

int main(int argc, char *argv[]){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    SolutionUnion solveUnion;
    SolutionDfs solveDfs;
    SolutionLeetcode solveLeetcode;
    int res1 = solveUnion.findCircleNum(isConnected);
    int res2 = solveDfs.findCircleNum(isConnected);
    int res3 = solveLeetcode.findCircleNum(isConnected);
    if(res1 == res2 && res2==res3){
        cout << res1 << endl;
    }else{
        cout << "error: " << "res1: " << res1 << "res2: " << res2 << "res3: " << res3 << endl;
    }
    return 0;
}