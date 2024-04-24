#include <functional>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
//#include <bit>
using namespace std;

char poptable[256] =
{
0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};
unsigned long long mypopcount(int u)
{
    return poptable[u & 0xFF] + poptable[(u >> 8) & 0xFF] + poptable[(u >> 16) & 0xFF] + poptable[(u >> 24) & 0xFF];

}

int answer(int x) {
    unsigned long long m = mypopcount(x);
    for (int i = x + 1; i <= 1e9; i++) {
        if (mypopcount(i) == m) { // __builtin_popcount(i) == m)
            return i;
        }
    }

    return -1;
}
int main(int argc, char* argv[]) {

    int n;
    cin >> n;

    vector<int> vec;
    while (n) {
        vec.push_back(n % 2);
        n /= 2;
    }

    vec.push_back(0);

    int one = 0, zero = 0;
    while (one < vec.size() && vec[one] == 0) one++;
    zero = one + 1;
    while (zero < vec.size() && vec[zero] == 1) zero++;
    swap(vec[one], vec[zero]);

    sort(vec.begin(), vec.begin() + zero, std::greater<int>());

    int ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        ans += (vec[i] * pow(2, i));
    }

    cout << ans << endl;

    return 0;
}