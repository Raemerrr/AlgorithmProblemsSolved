#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes;

pair<int, int> bfs(const int _start) {
    pair<int, int> result(-1, -1);
    queue<pair<int, int>> q;
    q.emplace(0, _start);
    vector<bool> visited(N, false);
    visited[_start] = true;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        result = max(result, front);
        q.pop();
        for (const int _next: nodes[front.second]) {
            if (!visited[_next]) {
                visited[_next] = true;
                q.emplace(front.first + 1, _next);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nodes.assign(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    pair<int, int> target = bfs(0);
    pair<int, int> answer = bfs(target.second);
    cout << ((answer.first % 2 == 0) ? (answer.first / 2) : (answer.first / 2 + 1)) << "\n";
    return 0;
}