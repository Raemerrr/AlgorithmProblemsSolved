#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;
const int START_INDEX = 65;
int R, C;
vector<vector<char>> board;
vector<bool> visited;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

bool checkRange(const int y, const int x) {
    return -1 < y && y < R && -1 < x && x < C;
}

int dfs(const int y, const int x) {
    int result = 0;
    for (int d = 0; d < 4; d++) {
        int tempY = y + dy[d];
        int tempX = x + dx[d];
        if (checkRange(tempY, tempX) && !visited[board[tempY][tempX] - START_INDEX]) {
            visited[board[tempY][tempX] - START_INDEX] = true;
            result = max(result, dfs(tempY, tempX));
            visited[board[tempY][tempX] - START_INDEX] = false;
        }
    }
    // result : 탐색 가능한 알파벳의 최대 수(자식의 숫자)
    // 1 : 자기 자신
    return result + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    visited.assign(ALPHABET_SIZE, false);
    board.assign(R, vector<char>(C, ' '));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    visited[board[0][0] - START_INDEX] = true;
    cout << dfs(0, 0) << "\n";
    return 0;
}