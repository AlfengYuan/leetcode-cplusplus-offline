#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    vector<pair<int, int>> lists(m);
    for (int i = 0; i < m; i++) {
        int sum = 0;
        string line;
        getline(cin >> ws, line);
        istringstream iss(line);
        int x;
        while (iss >> x) {
            sum += w[x];
        }
        lists[i] = make_pair(sum, i + 1);
    }
    sort(lists.begin(), lists.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    for (const auto& l : lists) {
        cout << l.second << endl;
    }
    return 0;
}