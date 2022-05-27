#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, treeHeight, answer;
vector<vector<int>> nodes, parents;
vector<int> depth;

void dfs(const int Cur) {
    for (const int Next: nodes[Cur]) {
        if (depth[Next] == -1) {
            depth[Next] = depth[Cur] + 1;
            parents[Next][0] = Cur;
            dfs(Next);
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

int find_LCA2(int a, int b) {
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
        for (int i = treeHeight - 1; i >= 0; i--) {
            if (parents[a][i] != -1 && parents[a][i] != parents[b][i]) {
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        a = parents[a][0];
    }
    return a;
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
        for (int i = treeHeight - 1; i >= 0; i--) {
            if (parents[a][i] != -1 && parents[a][i] != parents[b][i]) {
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
    treeHeight = (int) ceil(log2(N));
    nodes.assign(N, vector<int>());
    parents.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        nodes[a - 1].emplace_back(b - 1);
        nodes[b - 1].emplace_back(a - 1);
    }
    depth[0] = 0;
    dfs(0);
    make_parents();
    cin >> M;
    int Prev = 0;
    while (M--) {
        int Cur = 0;
        cin >> Cur;
        Cur--;
        int lca = find_LCA(Prev, Cur);
        answer += (depth[Prev] + depth[Cur] - (2 * depth[lca]));
        Prev = Cur;
    }
    cout << answer << "\n";
    return 0;
}