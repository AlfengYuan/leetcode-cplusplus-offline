#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int n, x;
    vector<int> height;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        height.push_back(x);
    }

    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        for (; j < n; j++) {
            if (height[j] > height[i]) {
                cout << j << " ";
                break;
            }
        }
        if (j == n) cout << 0 << " ";
    }

    cout << 0 << endl;

    return 0;
}