#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> cnt;
vector<vector<int>> nodes;

void proc() {
    queue<int> q;
    for (int i = 0; i < N; i++) if (cnt[i] == 0) q.push(i);
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        cout << _front + 1 << " ";
        for (const int _next: nodes[_front]) {
            cnt[_next]--;
            if (cnt[_next] == 0) q.push(_next);
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    nodes.assign(N, vector<int>());
    cnt.assign(N, 0);
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        nodes[a - 1].push_back(b - 1);
        cnt[b - 1]++;
    }
    proc();
    return 0;
}