#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int n, x, cap;
    int ans = 0;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }
    cin >> cap;

    sort(vec.begin(), vec.end());

    int left =0, right = n-1;
    for (; right >= left; right--) {
        if (vec[right] >= cap) ans++;
        else {
            int j = left;
            while (j < right && vec[j] + vec[right] < cap) j++;
            if (j == right) break;
            else {
                ans++;
                vec[j] = 0;
                left = j+1;
            }
        }
    }

    cout << ans << endl;



    return 0;
}