#include <vector>
#include <iostream>

using namespace std;
vector<int> vec;
int h;

bool check(int x) {
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
        cnt += (vec[i] + x - 1) / x;
        if (cnt > h) return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    int x;
    while (cin >> x) {
        vec.push_back(x);
        //if (cin.get() == '\n') break;
    }
    h = vec.back(); vec.pop_back();
    if (h < vec.size()) {
        cout << 0 << endl;
        return 0;
    }

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}