#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<vector<int>> idx;
vector<pair<int, int>> initPos;
deque<pair<int, int>> store;

int N, K, answer;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

bool checkRange(const int y, const int x) {
    if (0 <= y && y < N && 0 <= x && x < N) {
        return true;
    }
    return false;
}

int find_parent(const int idx) {
    if (idx == parent[idx]) {
        return idx;
    }
    return parent[idx] = find_parent(parent[idx]);
}

void merge(const int _a, const int _b) {
    int a = find_parent(_a);
    int b = find_parent(_b);
    if (a != b) {
        parent[b] = a;
    }
}

// 내 문명 전파 시키기
void bfs_merge() {
    for (int i = 0, size = store.size(); i < size; i++) {
        pair<int, int> front = store[i];
        for (int d = 0; d < 4; d++) {
            int tempY = front.first + dy[d];
            int tempX = front.second + dx[d];
            if (checkRange(tempY, tempX) && idx[tempY][tempX] > -1) {
                merge(idx[front.first][front.second], idx[tempY][tempX]);
            }
        }
    }
}

void bfs() {
    for (int i = 0, size = store.size(); i < size; i++) {
        pair<int, int> front = store.front();
        store.pop_front();
        for (int d = 0; d < 4; d++) {
            int tempY = front.first + dy[d];
            int tempX = front.second + dx[d];
            if (checkRange(tempY, tempX) && idx[tempY][tempX] == -1) {
                idx[tempY][tempX] = idx[front.first][front.second];
                store.emplace_back(tempY, tempX);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    parent.assign(N * N, -1);
    idx.assign(N, vector<int>(N, -1));

    while (0 < K) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        idx[a][b] = K;
        parent[idx[a][b]] = idx[a][b];
        initPos.emplace_back(a, b);
        store.emplace_back(a, b);
        K--;
    }

    while (true) {
        bfs_merge();
        bool flag = true;
        for (int i = 0; i < initPos.size() - 1; i++) {
            int a = idx[initPos[i].first][initPos[i].second];
            int b = idx[initPos[i + 1].first][initPos[i + 1].second];
            if (find_parent(a) != find_parent(b)) {
                flag = false;
                break;
            }
        }
        if (flag) break;
        bfs();
        answer++;
    }
    cout << answer << "\n";
    return 0;
}