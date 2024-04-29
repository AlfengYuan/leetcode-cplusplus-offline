#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
    int n, x, y;
    cin >> n >> x;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> y;
        vec.push_back(y);
    }

   /* int ans = 0;
    int sum = 0;
    for (int start = 0; start < vec.size(); start++) {
        int curr = ans;
        for (int end = start; end < vec.size(); end++) {
            sum += vec[end];
            if (sum >= x) {
                ans += (vec.size() - end);
                sum = 0;
                break;
            }
        }
        if (ans == curr) break;
    }*/

    long long ans = 0;
    long long sum = 0;
    int left = 0, right = -1;
    while (left < vec.size()) {
        while (right+1 < vec.size() && sum < x) {
            right++;
            sum += vec[right];
        }


        if (sum >= x) ans += (vec.size() - right);
        else break;

        sum -= vec[left];
        left++;
    }

    cout << ans << endl;
    return 0;
}