#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, treeHeight, answer;
vector<vector<int>> nodes, parents;
vector<int> depth;

void dfs(int _index) {
    for (const int _next: nodes[_index]) {
        if (depth[_next] == -1) {
            depth[_next] = depth[_index] + 1;
            parents[_next][0] = _index;
            dfs(_next);
        }
    }
}

void make_tree() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (parents[j][i] != -1) {
                parents[j][i + 1] = parents[parents[j][i]][i];
            }
        }
    }
}

int find_LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0) {
            a = parents[a][i];
        }
        diff /= 2;
    }
    if (a != b) {
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parents[a][i] != -1 && parents[a][i] != parents[b][i]){
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        a = parents[a][0];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nodes.assign(N, vector<int>());
    treeHeight = (int) ceil(log2(N));
    parents.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    for (int i = 0; i < N; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    depth[0] = 0;
    dfs(0);
    make_tree();
    cin >> M;
    int _prev = 0;
    while (M--) {
        int _cur = 0;
        cin >> _cur;
        _cur--;
        int lca = find_LCA(_prev, _cur);
        answer += depth[_prev] + depth[_cur] - (depth[lca] * 2);
    }
    cout << answer << "\n";
    return 0;
}