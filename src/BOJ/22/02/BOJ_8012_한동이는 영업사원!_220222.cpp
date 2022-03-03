#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, treeHeight;
vector<vector<int>> v, parent;
vector<int> depth;

void bfs(const int _start) {
    vector<vector<int>> og = v;
    v.assign(N, vector<int>());
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(_start);
    visited[_start] = true;
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: og[_front]) {
            if (!visited[_next]) {
                visited[_next] = true;
                v[_front].push_back(_next);
                q.push(_next);
            }
        }
    }
}

void make_parent() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (parent[j][i] != -1) {
                parent[j][i + 1] = parent[parent[j][i]][i];
            }
        }
    }
}

int find_LCA(int _a, int _b) {
    int a = _a;
    int b = _b;
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0) {
            s
                    a = parent[a][i];
        }
        diff /= 2;
    }
    if (a != b) {
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parent[a][i] != -1 && parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[a][b];
            }
        }
        a = parent[a][0];
    }
    return a;
}

void dfs(const int _index) {
    for (const int _next: v[_index]) {
        if (depth[_next] == -1) {
            depth[_next] = depth[_index] + 1;
            parent[_next][0] = _index;
            dfs(_next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, vector<int>());
    treeHeight = (int) ceil(log2(N));
    parent.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[0] = 0;
    dfs(0);
    make_parent();
    cin >>
    return 0;
}