#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
vector<int> vec;
int k;
int main(int argc, char *argv[]){
    cin >> n;
    int x;
    for(int i = 0; i<n; i++){
        cin >> x;
        vec.push_back(x);
    }
    cin >> k;

    vector<int> dp(n, 0);
    dp[0] = vec[0];
    dp[1] = dp[0] + vec[1];
    int before_index = (dp[0] > dp[1]? 0 : 1);

    for(int i = 2; i<n; i++){
        if(before_index < i-k){
            before_index = max_element(dp.begin() + max(0, i-k), dp.begin() + i) - dp.begin();
        }
        dp[i] = dp[before_index] + vec[i];
        if(vec[i] >= 0){
            before_index = i;
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}

// 1 -1 -6 7 -17 7