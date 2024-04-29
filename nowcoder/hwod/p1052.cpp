#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    int m, n, x;
    cin >> m >> n >> x;
    int input;
    vector<int> make;
    vector<int> risk;
    vector<int> money;
    for (int i = 0; i < m; i++) {
        cin >> input;
        make.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        cin >> input;
        risk.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        cin >> input;
        money.push_back(input);
    }

    vector<int> res(m, 0);
    long long result = 0;

    for (int i = 0; i < m; i++) {
        if (risk[i] <= x && money[i] <= n) {
            long long curr = 0;
            curr += make[i] * min(n, money[i]);
            if (curr > result) {
                result = curr;
                for (int k = 0; k < res.size(); k++) {
                    res[k] = 0;
                }
                res[i] = min(n, money[i]);
            }
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (risk[i] + risk[j] <= x && money[i]+money[j] <= n) {
                long long curr = 0;
                curr = make[i] * money[i] + make[j] * money[j];
                if(curr > result){
                    result = curr;
                    for(int k = 0; k<res.size(); k++){
                        res[k] = 0;
                    }
                    res[i] = money[i];
                    res[j] = money[j];
                }
            }
        }
    }

    for (int& i : res) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}