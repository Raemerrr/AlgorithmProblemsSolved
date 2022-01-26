#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<vector<int>> nodes;
map<int, int> m;

void dfs(const int idx) {
    for (const int Next: nodes[idx]) {
        m[Next] += m[idx];
        dfs(Next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    nodes.assign(N + 1, vector<int>());
    for (int i = 1; i <= N; i++) {
        int num = 0;
        cin >> num;
        if (num == -1) num = 0;
        nodes[num].push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        m[a] += b;
    }
    dfs(0);
    for (int i = 1; i <= N; i++) cout << m[i] << " ";
    cout << "\n";
    return 0;
}