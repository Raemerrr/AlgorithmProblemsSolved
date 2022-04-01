#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<pair<int, int>> emptyPos, virusPos;
vector<vector<int>> board;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

bool checkRange(const int y, const int x) {
    if (y >= 0 && y < N && x >= 0 && x < M) return true;
    return false;
}

int bfs(const vector<pair<int, int>> &select) {
    int result = emptyPos.size() - 3;
    vector<vector<int>> _board = board;
    for (const pair<int, int> &d: select) _board[d.first][d.second] = 1;
    queue<pair<int, int>> q;
    for (const pair<int, int> &d: virusPos) q.emplace(d);
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int tempY = front.first + dy[d];
            int tempX = front.second + dx[d];
            if (checkRange(tempY, tempX) && _board[tempY][tempX] == 0) {
                _board[tempY][tempX] = 2;
                q.emplace(tempY, tempX);
                result--;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) emptyPos.emplace_back(i, j);
            else if (board[i][j] == 2) virusPos.emplace_back(i, j);
        }
    }
    vector<int> select(emptyPos.size() - 3, 0);
    for (int i = 0; i < 3; i++) select.push_back(1);
    do {
        vector<pair<int, int>> temp;
        for (int i = 0; i < emptyPos.size(); i++) if (select[i] == 1) temp.push_back(emptyPos[i]);
        answer = max(answer, bfs(temp));
    } while (next_permutation(select.begin(), select.end()));
    cout << answer << "\n";
    return 0;
}