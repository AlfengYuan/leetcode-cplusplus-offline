#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    int m, n, x, y;
    cin >> m >> n;
    vector<vector<int>> board = vector<vector<int>>(m, vector<int>(n, 0));
    vector<int> digit;
    vector<int> count;
    int start = 0;
    while (cin >> x >> y) {
        digit.push_back(x);
        count.push_back(y);
        //for (int j = 0; j < count; j++) {
        //    board[start / m][start % n] = digit;
        //    start++;
        //}
        if (cin.get() == '\n') break;
    }

    cin >> x >> y;

    int end = x * n + y + 1;

    int i = 0;
    int res = 0;
    int sum = 1;
    while (i < count.size() && sum <= end) {
        sum += count[i++];
    }

    if (sum > end)  res = digit[i - 1];
       
    cout << res << endl;
    
    return 0;
}