#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < N && x >= 0 && x < M) return true;
    return false;
}

pair<int, int> bfs() {
    pair<int, int> result(0, 0);
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = true;
    queue<pair<int, int>> tempQ;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int tempY = front.first + dy[d];
            int tempX = front.second + dx[d];
            if (checkRange(tempY, tempX) && !visited[tempY][tempX]) {
                if (board[tempY][tempX] == 0) q.emplace(tempY, tempX);
                else tempQ.emplace(tempY, tempX);
                visited[tempY][tempX] = true;
            }
        }
        // 핵심 로직
        if (q.empty() && !tempQ.empty()) {
            result.first++;
            result.second = tempQ.size();
            while (!tempQ.empty()) {
                q.emplace(tempQ.front());
                tempQ.pop();
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    pair<int, int> answer = bfs();
    cout << answer.first << "\n" << answer.second << "\n";
    return 0;
}