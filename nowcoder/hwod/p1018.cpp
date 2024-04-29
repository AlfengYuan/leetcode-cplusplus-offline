#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
vector<int> cnt;
vector<int> ind;
int main(int argc, char* argv[]) {
    int n, x;
    cin >> n;
    
    map<int, int> mymap;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mymap.count(x) == 0) {
            mymap[x] = 1;
        }
        else {
            mymap[x]++;
        }
    }

    int k;
    cin >> k;

    vector<int> res;

    for (auto iter = mymap.begin(); iter != mymap.end(); iter++) {
        if (iter->second >= k) {
            ind.push_back(iter->first);
            cnt.push_back(iter->second);
        }
    }

    for (int i = 0; i < ind.size(); i++) {
        res.push_back(i);
    }

    sort(res.begin(), res.end(), [](int& a, int& b) {
        if (cnt[a] != cnt[b]) {
            return cnt[a] > cnt[b];
        }
        else {
            return ind[a] < ind[b];
        }
        });



    cout << res.size() << endl;

    for (int i = 0; i < res.size(); i++) {
        cout << ind[res[i]] << endl;
    }

    return 0;
}