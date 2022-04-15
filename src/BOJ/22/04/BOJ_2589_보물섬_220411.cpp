#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<vector<char>> board;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < N && x >= 0 && x < M) return true;
    return false;
}

int bfs(const int startY, const int startX) {
    int result = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[startY][startX] = true;
    queue<pair<int, int>> q;
    q.emplace(startY, startX);
    while (!q.empty()) {
        for (int i = 0, size = q.size(); i < size; i++) {
            pair<int, int> front = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tempY = front.first + dy[d];
                int tempX = front.second + dx[d];
                if (checkRange(tempY, tempX) && board[tempY][tempX] == 'L' && !visited[tempY][tempX]) {
                    visited[tempY][tempX] = true;
                    q.emplace(tempY, tempX);
                }
            }
        }
        result++;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.assign(N, vector<char>(M, ' '));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {
                answer = max(answer, bfs(i, j));
            }
        }
    }
    cout << answer - 1 << "\n";
    return 0;
}