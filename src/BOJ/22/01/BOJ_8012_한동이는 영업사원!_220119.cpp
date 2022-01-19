#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, treeHeight, answer;
vector<vector<int>> nodes, parent;
vector<int> depth;

void make_parent() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (parent[j][i] != -1) {
                parent[j][i + 1] = parent[parent[j][i]][i];
            }
        }
    }
}

void dfs(int Cur) {
    for (const int Next: nodes[Cur]) {
        if (depth[Next] == -1) {
            depth[Next] = depth[Cur] + 1;
            parent[Next][0] = Cur;
            dfs(Next);
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
    return a;
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
    int curPos = 0;
    for (int i = 0; i < M; i++) {
        int targetPos = 0;
        cin >> targetPos;
        targetPos--;
        int lca = find_LCA(curPos, targetPos);
        answer += (depth[curPos] + depth[targetPos] - (2 * depth[lca]));
        curPos = targetPos;
    }
    cout << answer << "\n";
    return 0;
}
