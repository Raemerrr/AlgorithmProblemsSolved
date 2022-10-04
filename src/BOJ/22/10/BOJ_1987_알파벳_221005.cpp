#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int START_INDEX = 'A';
const int END_INDEX = 'Z';
int R, C;
vector<vector<char>> board;
vector<bool> visited;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

bool checkRange(const int y, const int x) {
    return -1 < y && -1 < x && y < R && x < C;
}

int dfs(const int y, const int x) {
    int result = 1;
    int maxVal = 0;
    for (int d = 0; d < 4; d++) {
        int tempY = y + dy[d];
        int tempX = x + dx[d];
        if (checkRange(tempY, tempX) && !visited[board[tempY][tempX] - START_INDEX]) {
            visited[board[tempY][tempX] - START_INDEX] = true;
            maxVal = max(dfs(tempY, tempX), maxVal);
            visited[board[tempY][tempX] - START_INDEX] = false;
        }
    }
    return result + maxVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    board.assign(R, vector<char>(C, ' '));
    visited.assign(END_INDEX - START_INDEX + 1, false);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    visited[board[0][0] - START_INDEX] = true;
    cout << dfs(0, 0) << "\n";
    return 0;
}