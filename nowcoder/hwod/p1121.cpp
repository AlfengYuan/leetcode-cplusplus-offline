#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char g[N][N];
int n;
string s;
bool vis[N][N];
int dx[4]={-1,1,0,0}, dy[4]={0,0,1,-1};

bool dfs(int cnt, int x, int y, vector<pair<int,int>>& path) {
    // 判断是否越界、已访问或者当前位置字符不匹配
    if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || g[x][y] != s[cnt]) {
        return false;
    }

    // 如果已经找到字符串的最后一个字符，输出路径并返回 true
    if (cnt == s.size() - 1) {
        int m = path.size();
        for (int i = 0; i < m; i++) {
            printf("%d,%d", path[i].first, path[i].second);
            if (i < m - 1) {
                printf(",");
            }
        }
        return true;
    }

    // 标记当前位置已访问
    vis[x][y] = true;

    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int a = dx[i] + x;
        int b = dy[i] + y;

        // 记录路径
        path.push_back({a, b});

        // 递归调用 dfs
        if (dfs(cnt + 1, a, b, path)) {
            return true;
        }

        // 回溯，移除路径
        path.pop_back();
    }

    // 恢复当前位置未访问状态
    vis[x][y] = false;
    return false;
}

int main() {
    scanf("%d\n", &n);

    // 读取迷宫字符数组 g
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < n; j++) {
            g[i][j] = t[j * 2];
        }
    }

    // 读取目标字符串 s
    cin >> s;

    // 在迷宫中寻找字符串 s 的路径
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == s[0]) {
                memset(vis, 0, sizeof vis);
                vector<pair<int, int>> path = {{i, j}};
                if (dfs(0, i, j, path)) {
                    break;
                }
            }
        }
    }

    return 0;
}