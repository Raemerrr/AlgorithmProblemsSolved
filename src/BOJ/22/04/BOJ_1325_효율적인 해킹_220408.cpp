#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
vector<vector<int>> nodes;
map<int, vector<int>, greater<int>> m;

int bfs(int _start) {
    int cnt = 0;
    vector<int> visited(N, false);
    queue<int> q;
    q.push(_start);
    visited[_start] = true;
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: nodes[_front]) {
            if (!visited[_next]) {
                visited[_next] = true;
                q.push(_next);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    nodes.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        nodes[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < N; i++) {
        int cnt = bfs(i);
        m[cnt].push_back(i);
    }
    for (const int i: (*m.begin()).second) cout << i + 1 << " ";
    cout << "\n";
    return 0;
}