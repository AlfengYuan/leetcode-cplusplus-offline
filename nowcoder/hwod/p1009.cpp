// https://codefun2000.com/d/hwod/p/P1009
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board;
vector<vector<long long>> dp;
int h, w;
int main(int argc, char* argv[]) {
    cin >> h >> w;

    board = vector<vector<int>>(h, vector<int>(w, 0));
    int x;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> x;
            board[i][j] = x;
        }
    }

    dp = vector<vector<long long>>(h, vector<long long>(w, 0));

    for (int i = 0; i < w; i++) {
        if (board[0][i] == 1) break;
        dp[0][i] = 1;
    }

    for (int i = 0; i < h; i++) {
        if (board[i][0] == 1) break;
        dp[i][0] = 1;
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (board[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else if (board[i][j] == 1) {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}