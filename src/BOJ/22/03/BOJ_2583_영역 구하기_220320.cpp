#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<bool>> board, visited;
vector<pair<int, int>> position;
vector<int> answer;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool checkRange(const int y, const int x) {
    if (x >= 0 && x < M && y >= 0 && y < N) return true;
    return false;
}

void bfs(const int startY, const int startX) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.emplace(startY, startX);
    visited[startY][startX] = true;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int tempY = front.first + dy[d];
            int tempX = front.second + dx[d];
            if (checkRange(tempY, tempX) && !visited[tempY][tempX] && !board[tempY][tempX]) {
                visited[tempY][tempX] = true;
                q.emplace(tempY, tempX);
                cnt++;
            }
        }
    }
    answer.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    board.assign(N, vector<bool>(M, false));
    visited.assign(N, vector<bool>(M, false));
    position.assign(N, pair<int, int>(0, 0));
    for (int i = 0; i < K; i++) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                board[y][x] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j] && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (const int item: answer) cout << item << " ";
    cout << "\n";
    return 0;
}