#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF = 987654321;
int N, M, answer = INF;
vector<vector<int>> board;
vector<pair<int, int>> store, house;

vector<int> combi;
void dfs(const int idx) {
    if (combi.size() == M) {
        int result = 0;
        vector<int> dist(house.size(), INF);
        for (const int d: combi) {
            for (int i = 0; i < house.size(); i++) {
                dist[i] = min(dist[i], abs(house[i].first - store[d].first) + abs(house[i].second - store[d].second));
            }
        }
        for (const int d: dist) result += d;
        answer = min(answer, result);
    } else {
        for (int i = idx; i < store.size(); i++) {
            combi.push_back(i);
            dfs(i + 1);
            combi.pop_back();
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
                house.emplace_back(i + 1, j + 1);
            } else if (board[i][j] == 2) {
                store.emplace_back(i + 1, j + 1);
            }
        }
    }
    dfs(0);
    cout << answer << "\n";
    return 0;
}