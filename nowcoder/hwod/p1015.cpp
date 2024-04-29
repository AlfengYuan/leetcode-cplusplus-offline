#include <iostream>
#include <vector>
#include <string>
#include <numeric>


using namespace std;
int main(int argc, char* argv[]) {
    int n, x, v;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec[i] = x;
    }
    cin >> v;


    int left = 0, right = 0;
    int sum = 0;

    int ans = 0;

    if (accumulate(vec.begin(), vec.end(), 0) <= v) {
        cout << n << endl;
        return 0;
    }
    while (right < n) {
        
        if (sum > v) {
            ans = max(ans, right - left - 1);
            sum -= vec[left];
            left++;
        }
        else {
            sum += vec[right];
            right++;
        }
    }

    cout << ans << endl;



    return 0;
}