#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> g[26];
int d[26];
bool vis[26];

int main() {
    string s;

    while (cin >> s) {
        int a = s[0] - 'A', b = s[3] - 'A';
        d[a]++;
        g[b].push_back(a);
        vis[a] = vis[b] = true;
        if (cin.get() == '\n') break;
    }

    queue<int> q;
    vector<int> res, v;

    for (int i = 0; i < 26; i++) {
        if (!d[i] && vis[i]) {
            q.push(i);
            v.push_back(i);
        }
    }

    while (q.size()) {
        int sz = q.size();
        sort(v.begin(), v.end());
        for (int& x : v) {
            res.push_back(x);
        }
        v.clear();

        while (sz--) {
            int t = q.front();
            q.pop();

            for (int& x : g[t]) {
                d[x]--;
                if (!d[x]) {
                    q.push(x);
                    v.push_back(x);
                }
            }
        }
    }

    for (int& x : res) {
        char ch = x + 'A';
        cout << ch << " ";
    }

    return 0;
}


//A->B C->B
//B A C