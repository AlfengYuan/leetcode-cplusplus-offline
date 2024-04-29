#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int g[N][N], n, m;
bool vis[N][N];
int res;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

// DFS 函数，返回从当前位置出发的最长可行移动路径的长度
int dfs(int x, int y, int dirc, int cnt) {
    vis[x][y] = true;
    res = max(res, cnt);

    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int a = dx[i] + x, b = dy[i] + y;

        // 判断下一个位置是否在矩阵范围内，且未被访问过，且高度不相同
        if (a >= 0 && a < n && b >= 0 && b < m && !vis[a][b] && g[a][b] != g[x][y]) {
            int d = g[a][b] > g[x][y];
            
            // 判断下一个位置的高度与当前位置的高度的关系是否满足条件
            if (d != dirc) {
                dfs(a, b, d, cnt + 1);
            }
        }
    }

    // 回溯，将当前位置的标记重置为未访问
    vis[x][y] = false;
    return cnt;
}

int main() {
    cin >> n >> m;

    // 读取矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    // 遍历所有起点，以每个位置为起点进行 DFS 调用
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(vis, 0, sizeof vis);
            dfs(i, j, -1, 0);
        }
    }

    // 输出最终结果
    cout << res << endl;

    return 0;
}