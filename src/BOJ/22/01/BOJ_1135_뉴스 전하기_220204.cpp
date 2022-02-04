#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes;

int dfs(const int Cur) {
    int result = 0;
    int weight = nodes[Cur].size();
    vector<int> v;
    for (const int Next: nodes[Cur]) {
        v.push_back(dfs(Next));
    }
    sort(v.begin(), v.end());
    for (const int d : v) {
        result = max(result, d + weight--);
    }
    return result;
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
    cout << dfs(0) << "\n";
    return 0;
}