#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int treeHeight, N, M, answer;
vector<vector<int>> nodes, parents;
vector<int> depth;

void bfs(const int _start) {
    vector<vector<int>> og = nodes;
    nodes.assign(N, vector<int>());
    queue<int> q;
    q.push(_start);
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: og[_front]) {
            if (depth[_next] == -1) {
                depth[_next] = depth[_front] + 1;
                nodes[_front].push_back(_next);
                parents[_next][0] = _front;
                q.push(_next);
            }
        }
    }
}

void make_parents() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (parents[j][i] != -1) {
                parents[j][i + 1] = parents[parents[j][i]][i];
            }
        }
    }
}

int find_LAC(int _a, int _b) {
    if (depth[_a] < depth[_b]){
        swap(_a, _b);
    }
    int diff = depth[_a] - depth[_b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0){
            _a = parents[_a][i];
        }
        diff /= 2;
    }
    if (_a != _b){
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parents[_a][i] != -1 &&parents[_a][i] != parents[_b][i]){
                _a = parents[_a][i];
                _b = parents[_b][i];
            }
        }
        _a = parents[_a][0];
    }
    return _a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    treeHeight = (int) ceil(log2(N));
    nodes.assign(N, vector<int>());
    parents.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    depth[0] = 0;
    bfs(0);
    make_parents();
    cin >> M;
    int _prev = 0;
    while (M--){
        int _cur = 0;
        cin >> _cur;
        _cur--;
        int lca = find_LAC(_prev, _cur);
        answer += depth[_prev] + depth[_cur] - (2 * depth[lca]);
        _prev = _cur;
    }
    cout << answer << "\n";
    return 0;
}