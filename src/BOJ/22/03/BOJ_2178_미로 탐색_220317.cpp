#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, M;
vector<string> board;
vector<vector<int>> dist;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < N && x >= 0 && x < M) return true;
    return false;
}

int bfs(const int startY, const int startX) {
    queue<pair<int, int>> q;
    q.emplace(startY, startX);
    dist[startY][startX] = 1;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int tempY = front.first + dy[d];
            int tempX = front.second + dx[d];
            if (checkRange(tempY, tempX) && board[tempY][tempX] == '1' &&
                dist[front.first][front.second] + 1 < dist[tempY][tempX]) {
                dist[tempY][tempX] = dist[front.first][front.second] + 1;
                q.emplace(tempY, tempX);
            }
        }
    }
    return dist[N - 1][M - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.assign(N, "");
    dist.assign(N, vector<int>(M, INF));
    for (int i = 0; i < N; i++) cin >> board[i];
    cout << bfs(0, 0) << "\n";
    return 0;
}