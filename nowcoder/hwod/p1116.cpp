// #include <vector>
// #include <iostream>
// #include <string>
// #include <climits>
// using namespace std;

// int n, x;
// vector<vector<int>> board;
// vector<vector<bool>> used;
// vector<int> mo = {-1, -1};
// vector<int> son = {-1, -1};
// vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// pair<int, int> res = {INT_MAX, -1};


// void dfs(int x, int y, int step, int candy){
//     if(x==son[0] && y==son[1]){
//         if(step < res.first){
//             res.first = step;
//             res.second = candy;
//         }else if(step == res.first){
//             res.second = max(res.second, candy);
//         }

//         return;
//     }

//     if(x < 0 || x >= n || y < 0 || y >= n) return;

//     if(board[x][y] == -1) return;

//     if(used[x][y]) return;

//     used[x][y] = true;

//     for(auto d: dirs){
//         int now_x = x + d[0];
//         int now_y = y + d[1];
//         if(board[x][y] >= 0) dfs(now_x, now_y, step+1, candy+board[x][y]);
//         else dfs(now_x, now_y, step+1, candy);
//     }


//     used[x][y] = false;

// }
// int main(int argc, char *argv[]){
    
//     cin >> n;
    

//     board = vector<vector<int>>(n, vector<int>(n, 0));
//     used = vector<vector<bool>>(n, vector<bool>(n, false));
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<n; j++){
//             cin >> x;
//             board[i][j] = x;

//             if(x == -3) {
//                 mo[0] = i, mo[1] = j;
//             }else if(x == -2){
//                 son[0] = i, son[1] = j;
//             }
//         }
//     }

//     dfs(mo[0], mo[1], 0, 0);

//     cout << res.second << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义广度优先搜索函数
int bfs(queue<pair<int, int>>& q, vector<vector<int>>& g, vector<vector<int>>& w, vector<int>& dx, vector<int>& dy, int n) {
    while (!q.empty()) {
        // 从队列中取出当前位置
        pair<int, int> t = q.front();
        q.pop();
        int x = t.first, y = t.second;

        // 如果当前位置为终点，返回糖果数量
        if (g[x][y] == -2) {
            return w[x][y];
        }

        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i], y1 = y + dy[i];

            // 判断是否越界或者是不可访问的位置
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || g[x1][y1] == -1) {
                continue;
            }

            // 如果该位置未访问过，将其加入队列，并初始化糖果数量为0
            if (w[x1][y1] == 0) {
                q.push({x1, y1});
                w[x1][y1] = 0;
            }

            // 更新糖果数量，取当前位置糖果数和上一步位置的糖果数量之和的最大值
            w[x1][y1] = max(w[x1][y1], max(0, g[x1][y1]) + w[x][y]);
        }
    }
    // 如果无法到达终点，返回-1
    return -1;
}

int main() {
    int n;
    cin >> n;

    // 存储糖果数量的二维数组w，初始值为0
    vector<vector<int>> w(n, vector<int>(n, 0));

    // 存储起点坐标的队列
    queue<pair<int, int>> q;

    // 存储地图元素的二维数组g
    vector<vector<int>> g(n, vector<int>(n, 0));

    // 读取地图元素并初始化起点和糖果数量数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == -3) {  // 添加起点
                q.push({i, j});
                w[i][j] = 0;
            }
        }
    }

    // 四个方向的移动
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    // 调用广度优先搜索函数获取结果
    int result = bfs(q, g, w, dx, dy, n);
    cout << result << endl;

    return 0;
}