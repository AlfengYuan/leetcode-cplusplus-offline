#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    int c = n / m;
    if (n % m != 0) c++;

    vector<vector<string>> board(m, vector<string>(c, "*"));


    int x = 0, y = 0;
    vector<vector<int>> dir{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int i = 1;
    while (i <= n) {
        while (i <= n && y < c && board[x][y]=="*") {
            board[x][y] = to_string(i);
            y++;
            i++;
        }
        y--; x++;

        while (i <= n && x < m && board[x][y] == "*") {
            board[x][y] = to_string(i);
            x++;
            i++;
        }
        x--; y--;

        while (i <= n && y >= 0 && board[x][y] == "*") {
            board[x][y] = to_string(i);
            y--;
            i++;
        }
        y++; x--;

        while (i <= n && x >= 0 && board[x][y] == "*") {
            board[x][y] = to_string(i);
            x--;
            i++;
        }
        x++; y++;
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}