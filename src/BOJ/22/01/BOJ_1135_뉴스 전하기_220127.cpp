#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes;

int dfs(const int idx) {
    int result = 0;
    int weight = nodes[idx].size() - 1;
    vector<int> rank;
    for (const int Next: nodes[idx]) {
        rank.push_back(dfs(Next));
    }
    sort(rank.begin(), rank.end());
    for (int i = 0; i < rank.size(); i++) {
        result = max(result, rank[i] + weight--);
    }
    return result + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nodes.assign(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        if (num == -1) continue;
        nodes[num].push_back(i);
    }
    cout << dfs(0) - 1 << "\n";
    return 0;
}