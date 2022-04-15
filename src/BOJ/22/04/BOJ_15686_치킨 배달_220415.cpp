#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M, answer = INF;
vector<vector<int>> board;
vector<pair<int, int>> house, store, selectedStore;

void dfs(const int idx, int cnt) {
    if (cnt == M) {
        int sum = 0;
        for (const pair<int, int> &h: house) {
            int dist = INF;
            for (const pair<int, int> &s: selectedStore) {
                dist = min(dist, abs(h.first - s.first) + abs(h.second - s.second));
            }
            sum += dist;
        }
        answer = min(answer, sum);
    } else {
        for (int i = idx; i < store.size(); i++) {
            selectedStore.push_back(store[i]);
            dfs(i + 1, cnt + 1);
            selectedStore.pop_back();
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
                house.emplace_back(i, j);
            } else if (board[i][j] == 2) {
                store.emplace_back(i, j);
            }
        }
    }
    dfs(0, 0);
    cout << answer << "\n";
    return 0;
}