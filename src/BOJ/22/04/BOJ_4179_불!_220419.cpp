#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int R, C, answer;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
vector<vector<char>> board;
queue<pair<int, int>> JQ, FQ;
vector<vector<bool>> JVisited, FVisited;

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < R && x >= 0 && x < C) return true;
    return false;
}

bool bfs() {
    while (!JQ.empty()) {
        answer++;
        for (int i = 0, size = JQ.size(); i < size; i++) {
            pair<int, int> front = JQ.front();
            JQ.pop();
            if (board[front.first][front.second] == 'F') continue;
            for (int d = 0; d < 4; d++) {
                int tempY = front.first + dy[d];
                int tempX = front.second + dx[d];
                if (checkRange(tempY, tempX)) {
                    if (!JVisited[tempY][tempX] && (board[tempY][tempX] == '.' || board[tempY][tempX] == 'J')) {
                        JVisited[tempY][tempX] = true;
                        JQ.emplace(tempY, tempX);
                    }
                } else {
                    return true;
                }
            }
        }
        for (int i = 0, size = FQ.size(); i < size; i++) {
            pair<int, int> front = FQ.front();
            FQ.pop();
            for (int d = 0; d < 4; d++) {
                int tempY = front.first + dy[d];
                int tempX = front.second + dx[d];
                if (checkRange(tempY, tempX) && !FVisited[tempY][tempX] && board[tempY][tempX] != '#') {
                    FVisited[tempY][tempX] = true;
                    FQ.emplace(tempY, tempX);
                    board[tempY][tempX] = 'F';
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    board.assign(R, vector<char>(C, ' '));
    JVisited.assign(R, vector<bool>(C, false));
    FVisited.assign(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'J') {
                JQ.emplace(i, j);
                JVisited[i][j] = true;
            } else if (board[i][j] == 'F') {
                FQ.emplace(i, j);
                FVisited[i][j] = true;
            }
        }
    }
    cout << (bfs() ? to_string(answer) : "IMPOSSIBLE") << "\n";
    return 0;
}