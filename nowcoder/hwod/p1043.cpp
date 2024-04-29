#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;
int n;
int ans = 1;

bool check(int x, int c) {
    float max = x * c + c * (c - 1) / 2.;
    float min = x * c - c * (c - 1) / 2;
    if (n < min || n > max) return false;

    return true;
}

bool getResult(int x, int c) {
    vector<int> curr(c, 0);
    for (int i = 0; i < c; i++) {
        curr[i] = x;
        for (int j = i - 1; j >= 0; j--) {
            curr[j] = curr[j + 1] - 1;
            if (curr[j] <= 0) return false;
        }
        for (int j = i + 1; j < c; j++) {
            curr[j] = curr[j - 1] + 1;
        }

        if (accumulate(curr.begin(), curr.end(), 0) == n) {
            cout << n << "=";
            for (int i = 0; i < c; i++) {
                cout << curr[i];
                if (i != c - 1) cout << "+";
            }
            cout << endl;
            ans++;
            return true;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {

    cin >> n;

    cout << n << "=" << n << endl;
    for (int i = 2; i < n; i++) {
        int x = n / i;
        if (check(x, i)) {
            if (!getResult(x, i));
        }
    }

    cout << "Result:" << ans << endl;

    return 0;
}