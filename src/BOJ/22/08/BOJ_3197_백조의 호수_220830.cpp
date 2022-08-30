#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, answer;
vector<int> parent;
vector<vector<char>> board;
vector<pair<int, int>> swans;
vector<vector<int>> ids;
deque<pair<int, int>> dq;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool checkRange(const int y, const int x) {
    return -1 < y && y < R && -1 < x && x < C;
}

int findParent(const int key) {
    if (parent[key] == key) return key;
    return parent[key] = findParent(parent[key]);
}

void mergeParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return;
    parent[b] = a;
}

void merge() {
    for (const pair<int, int> &p: dq) {
        for (int d = 0; d < 4; d++) {
            int tempY = p.first + dy[d];
            int tempX = p.second + dx[d];
            if (checkRange(tempY, tempX) && board[tempY][tempX] != 'X') {
                mergeParent(ids[p.first][p.second], ids[tempY][tempX]);
            }
        }
    }
}

void melt() {
    for (int i = 0, size = dq.size(); i < size; i++) {
        int curY = dq.front().first;
        int curX = dq.front().second;
        dq.pop_front();
        for (int d = 0; d < 4; d++) {
            int tempY = curY + dy[d];
            int tempX = curX + dx[d];
            if (checkRange(tempY, tempX) && board[tempY][tempX] == 'X') {
                board[tempY][tempX] = '.';
                dq.emplace_back(tempY, tempX);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    board.assign(R, vector<char>(C, ' '));
    ids.assign(R, vector<int>(C, 0));
    parent.assign(R * C, 0);
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            parent[cnt] = cnt;
            ids[i][j] = cnt;
            if (board[i][j] != 'X') {
                if (board[i][j] == 'L') {
                    swans.emplace_back(i, j);
                }
                dq.emplace_back(i, j);
            }
            cnt++;
        }
    }
    while (true) {
        merge();
        int swanAParent = findParent(ids[swans[0].first][swans[0].second]);
        int swanBParent = findParent(ids[swans[1].first][swans[1].second]);
        if (swanAParent == swanBParent) break;
        melt();
        answer++;
    }
    cout << answer << "\n";
    return 0;
}