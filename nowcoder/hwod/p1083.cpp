#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> cnt;
unordered_map<int, int> idx;
int main(int argc, char* argv[]) {
    string input;
    getline(cin, input);
    stringstream ss(input);
    string tmp;
    vector<int> vec;
    int x;
    
    vector<int> res;
    
    while (getline(ss, tmp, ',')) {
        x = atol(tmp.c_str());
        vec.push_back(x);
    }

    for (int i = 0; i < vec.size(); i++) {
        x = vec[i];
        cnt[x]++;
        if (idx.find(x) == idx.end()) {
            idx[x] = i;
        }
    }

    for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
        res.push_back(iter->first);
    }

    sort(res.begin(), res.end(), [](int &a, int &b) {
        if (cnt[a] != cnt[b]) {
            return cnt[a] > cnt[b];
        }
        else {
            return idx[a] < idx[b];
        }
        });

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) cout << ",";
    }

    cout << endl;

    return 0;

}