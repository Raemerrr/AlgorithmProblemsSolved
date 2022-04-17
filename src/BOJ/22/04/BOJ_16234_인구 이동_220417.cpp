#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, L, R, answer;
vector<vector<int>> board;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < N && x >= 0 && x < N) return true;
    return false;
}

bool checkOption(int y1, int x1, int y2, int x2) {
    int diff = abs(board[y1][x1] - board[y2][x2]);
    if (L <= diff && diff <= R) return true;
    return false;
}

bool bfs() {
    bool result = false;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                queue<pair<int, int>> q;
                q.emplace(i, j);
                visited[i][j] = true;
                int sum = board[i][j];
                vector<pair<int, int>> country;
                country.emplace_back(i, j);
                while (!q.empty()) {
                    int y1 = q.front().first;
                    int x1 = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int y2 = y1 + dy[d];
                        int x2 = x1 + dx[d];
                        if (checkRange(y2, x2) && !visited[y2][x2] && checkOption(y1, x1, y2, x2)) {
                            country.emplace_back(y2, x2);
                            visited[y2][x2] = true;
                            q.emplace(y2, x2);
                            sum += board[y2][x2];
                        }
                    }
                }
                if (country.size() > 1) {
                    result = true;
                    int value = sum / ((int) country.size());
                    for (const pair<int, int> &p: country) board[p.first][p.second] = value;
                }
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L >> R;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    while (bfs()) answer++;
    cout << answer << "\n";
    return 0;
}