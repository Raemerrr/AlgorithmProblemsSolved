#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> inDegree;
vector<vector<int>> nodes;

void bfs() {
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.emplace(i);
        }
    }
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        cout << _front + 1 << " ";
        for (const int _next: nodes[_front]) {
            inDegree[_next]--;
            if (inDegree[_next] == 0) {
                q.emplace(_next);
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    inDegree.assign(N, 0);
    nodes.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        inDegree[b - 1]++;
        nodes[a - 1].push_back(b - 1);
    }
    bfs();
    return 0;
}