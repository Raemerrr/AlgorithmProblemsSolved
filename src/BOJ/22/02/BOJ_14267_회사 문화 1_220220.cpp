#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> nodes;
vector<int> cost;

void dfs(const int _index) {
    for (const int _next: nodes[_index]) {
        cost[_next] += cost[_index];
        dfs(_next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    nodes.assign(N, vector<int>());
    cost.assign(N, 0);
    for (int i = 0; i < N; i++) {
        int _index = 0;
        cin >> _index;
        if (_index == -1) continue;
        _index--;
        nodes[_index].push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int _index = 0, _cost = 0;
        cin >> _index >> _cost;
        _index--;
        cost[_index] += _cost;
    }
    dfs(0);
    for (const int d: cost) cout << d << " ";
    cout << "\n";
    return 0;
}