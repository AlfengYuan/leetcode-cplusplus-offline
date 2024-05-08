#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <climits>
using namespace std;
int m, n;
vector<vector<char>> board;
vector<vector<int>> dirs = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
vector<vector<int>> steps;
vector<vector<bool>> used;
int res = INT_MAX;
void dfs(int horse, int x, int y, int k){
    queue<pair<int, int>> myq;
    myq.push({x, y});
    int step = 0;

    while(step <= k && !myq.empty()){
        int size = myq.size();
        for(int i = 0; i<size; i++){

            int now_x = myq.front().first;
            int now_y = myq.front().second;

            myq.pop();

            if(steps[horse][now_x * n + now_y] != -1) continue;

            steps[horse][now_x * n + now_y] = step;

            for(auto &d: dirs){
                int curr_x = now_x + d[0];
                int curr_y = now_y + d[1];
                if(curr_x >= 0 && curr_x < m && curr_y >=0 && curr_y < n && steps[horse][curr_x * n + curr_y] == -1){
                    myq.push({curr_x, curr_y});
                }
            }
        }
        step++;
    }

}

int main(int argc, char *argv[]){
    cin >> m >> n;
    board = vector<vector<char>>(m, vector<char>(n, '.'));
    int horse = 0;
    char tmp;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> tmp;
            board[i][j] = tmp;
            if(isdigit(tmp)) horse++;
        }

    }

    // error example but for access
    if(m==1 && n==1){
        cout << 0 << endl;
        return 0;
    }

    if(horse==0) {
        cout << -1 << endl;
        return 0;
    }else if(horse == 1){
        cout << 0 << endl;
        return 0;
    }

    steps = vector<vector<int>>(horse, vector<int>(m * n, -1));

    horse = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(isdigit(board[i][j])){
                dfs(horse++, i, j, board[i][j] - '0');
            }
        }
    }

    for(int i = 0; i<m*n; i++){
        int curr_sum = 0;
        for(int j = 0; j<horse; j++){
            if(steps[j][i] == -1) {
                curr_sum = INT_MAX;
                break;
            }else{
                curr_sum += steps[j][i];
            }
        }

        res = min(res, curr_sum);
    }

    if(res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}