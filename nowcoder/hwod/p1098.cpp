#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100005];

int solve() {
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 使用小顶堆作为待处理队列

    for (int i = 0; i < 100005; i++) {
        while (!pq.empty() && pq.top() < i) {
            pq.pop(); // 第一步：移除已经结束的任务
        }

        if (!a[i].empty()) {
            for (int j = 0; j < a[i].size(); j++) {
                pq.push(a[i][j]); // 第二步：将当前时刻开始的任务加入队列
            }
        }

        if (!pq.empty()) {
            ans++;
            pq.pop(); // 第三步：从队列中取出结束时间最早的任务，安排在这一天
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n; // 输入任务数量

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y); // 存储任务的开始和结束时间
    }

    cout << solve() << endl;

    return 0;
}