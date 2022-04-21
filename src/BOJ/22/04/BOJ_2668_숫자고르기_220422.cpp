#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> nodes;
vector<int> answer;
vector<bool> visited;

int bfs(const int _start) {
    queue<int> q;
    q.emplace(_start);
    visited[_start] = true;
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: nodes[_front]) {
            // 종료 조건 충족
            if (_next == _start) return _start;
            if (!visited[_next]) {
                visited[_next] = true;
                q.emplace(_next);
            }
        }
    }
    // 종료 조건 미충족
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nodes.assign(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        nodes[i].push_back(num - 1);
    }
    for (int i = 0; i < N; i++) {
        visited.assign(N, false);
        int idx = bfs(i);
        if (idx != -1) answer.push_back(idx);
    }
    cout << answer.size() << "\n";
    for (const int d: answer) cout << d + 1 << "\n";
    return 0;
}