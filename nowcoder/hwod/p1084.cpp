#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char* argv[]) {
    int x;
    vector<int> vec;
    int res = 0;
    while (cin >> x) {
        vec.push_back(x);
        if (cin.get() == '\n') break;
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        if (i > 0 && vec[i] == vec[i - 1]) continue;
        res += vec[i] + 1;
    }

    cout << res << endl;
    return 0;
}