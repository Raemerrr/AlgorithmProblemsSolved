#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N, answer;
vector<vector<int>> board;

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < N && x >= 0 && x < N) return true;
    return false;
}

int bfs(const int height) {
    int result = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && board[i][j] > height) {
                visited[i][j] = true;
                q.emplace(i, j);
                while (!q.empty()) {
                    pair<int, int> front = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int tempY = front.first + dy[d];
                        int tempX = front.second + dx[d];
                        if (checkRange(tempY, tempX) && !visited[tempY][tempX] && board[tempY][tempX] > height) {
                            visited[tempY][tempX] = true;
                            q.emplace(tempY, tempX);
                        }
                    }
                }
                result++;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    for (int i = 0; i <= 100; i++) answer = max(answer, bfs(i));
    cout << answer << "\n";
    return 0;
}