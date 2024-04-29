#include <iostream>
#include <vector>

using namespace std;

int res = 0;

int check(int x, int y) {
    int ans = 0;
    while (x) {
        ans += (x % 10);
        x /= 10;
    }

    while (y) {
        ans += (y % 10);
        y /= 10;
    }

    return ans;
}

void dfs(vector<vector<int>> &board, vector<vector<bool>> &used, int x, int y, int k) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;

    if (used[x][y]) return;

    if (check(x, y) > k) return;

    used[x][y] = true;

    res++;

    dfs(board, used, x - 1, y, k);
    dfs(board, used, x + 1, y, k);
    dfs(board, used, x, y - 1, k);
    dfs(board, used, x, y + 1, k);
}
int main(int argc, char* argv[]) {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> board = vector<vector<int>>(m, vector<int>(n, 0));
    vector<vector<bool>> used = vector<vector<bool>>(m, vector<bool>(n, false));
    dfs(board, used, 0, 0, k);

    cout << res << endl;
    return 0;
}