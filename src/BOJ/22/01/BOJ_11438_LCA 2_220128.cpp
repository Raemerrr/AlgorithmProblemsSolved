#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, treeHeight;
vector<vector<int>> nodes, parent;
vector<int> depth;

void dfs(const int _idx) {
    for (const int _next: nodes[_idx]) {
        if (depth[_next] == -1) {
            parent[_next][0] = _idx;
            depth[_next] = depth[_idx] + 1;
            dfs(_next);
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

int find_LCA(const int _a, const int _b) {
    int a = _a;
    int b = _b;
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0) {
            a = parent[a][i];
        }
        diff /= 2;
    }
    if (a != b) {
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parent[a][i] != -1 && parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        a = parent[a][0];
    }
    return a + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    treeHeight = (int) ceil(log2(N));
    nodes.assign(N, vector<int>());
    parent.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    depth[0] = 0;
    dfs(0);
    make_parent();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        cout << find_LCA(a, b) << "\n";
    }
    return 0;
}