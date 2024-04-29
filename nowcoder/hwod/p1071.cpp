#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int x;
    vector<int> vec;
    int nums[1005] = {0};
    int maxN = 0;
    while (cin >> x) {
        nums[x]++;
        if (nums[x] > maxN) {
            vec.clear();
            vec.push_back(x);
            maxN = nums[x];
        }
        else if (nums[x] == maxN) {
            vec.push_back(x);
        }
        if (cin.get() == '\n') break;
    }

    sort(vec.begin(), vec.end());

    if (vec.size() <= 1) cout << vec[0] << endl;
    else if (vec.size() % 2 != 0) cout << vec[vec.size() / 2] << endl;
    else {
        int n = vec.size() / 2;
        cout << (vec[n - 1] + vec[n]) / 2 << endl;
    }

    return 0;
}