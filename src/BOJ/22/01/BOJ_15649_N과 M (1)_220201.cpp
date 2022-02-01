#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<bool> check;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            check[i] = true;
            v[depth] = i;
            dfs(depth + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(N + 1, 0);
    check.assign(N + 1, false);
    dfs(0);
    return 0;
}