#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, answer;
vector<vector<int>> keys;
vector<int> parent;
deque<pair<int, int>> dq, swanPos;
vector<vector<char>> board;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int find_parent(const int key) {
    if (key == parent[key]) return key;
    return parent[key] = find_parent(parent[key]);
}

void merge(const int a, const int b) {
    int aParent = find_parent(a);
    int bParent = find_parent(b);
    if (aParent == bParent) return;
    parent[bParent] = aParent;
}

bool checkRange(const int y, const int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}

void bfs_merge() {
    for (int i = 0, size = dq.size(); i < size; i++) {
        int curY = dq[i].first;
        int curX = dq[i].second;
        for (int d = 0; d < 4; d++) {
            int tempY = curY + dy[d];
            int tempX = curX + dx[d];
            if (checkRange(tempY, tempX) && keys[tempY][tempX] >= 0 && keys[tempY][tempX] != keys[curY][curX]) {
                merge(keys[curY][curX], keys[tempY][tempX]);
            }
        }
    }
}

void bfs_melt() {
    for (int i = 0, size = dq.size(); i < size; i++) {
        int curY = dq.front().first;
        int curX = dq.front().second;
        dq.pop_front();
        for (int d = 0; d < 4; d++) {
            int tempY = curY + dy[d];
            int tempX = curX + dx[d];
            if (checkRange(tempY, tempX) && keys[tempY][tempX] < 0) {
                dq.emplace_back(tempY, tempX);
                keys[tempY][tempX] = keys[curY][curX];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    keys.assign(R, vector<int>(C, -1));
    parent.assign(R * C, -1);
    board.assign(R, vector<char>(C, '.'));
    int key = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            parent[key] = key;
            if (board[i][j] == '.' || board[i][j] == 'L') {
                keys[i][j] = key;
                dq.emplace_back(i, j);
                if (board[i][j] == 'L') {
                    swanPos.emplace_back(i, j);
                }
            }
            key++;
        }
    }
    while (true) {
        bfs_merge();
        int swanAParent = find_parent(keys[swanPos[0].first][swanPos[0].second]);
        int swanBParent = find_parent(keys[swanPos[1].first][swanPos[1].second]);
        if (swanAParent == swanBParent) break;
        bfs_melt();
        answer++;
    }
    cout << answer << "\n";
    return 0;
}
