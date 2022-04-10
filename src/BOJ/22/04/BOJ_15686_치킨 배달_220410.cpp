#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer = 987654321;
vector<vector<int>> board;
vector<pair<int, int>> store, home, selectedStore;
vector<bool> visited;

void dfs(int index, int cnt) {
    if (cnt == M) {
        int sum = 0;
        for (const pair<int, int> &h: home) {
            int dist = 987654321;
            for (const pair<int, int> &s: selectedStore) {
                dist = min(dist, (abs(h.first - s.first) + abs(h.second - s.second)));
            }
            sum += dist;
        }
        answer = min(answer, sum);
    } else {
        for (int i = index; i < store.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                selectedStore.push_back(store[i]);
                dfs(i, cnt + 1);
                selectedStore.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                home.emplace_back(i, j);
            } else if (board[i][j] == 2) {
                store.emplace_back(i, j);
            }
        }
    }
    visited.assign(store.size(), false);
    dfs(0, 0);
    cout << answer << "\n";
    return 0;
}