#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<vector<int>> powers;
bool visited[61][61][61];

struct Data {
    int a;
    int b;
    int c;

    Data(int a, int b, int c) : a(a), b(b), c(c) {}
};

void initPower() {
    vector<int> power{1, 3, 9};
    sort(power.begin(), power.end());
    do {
        powers.emplace_back(power);
    } while (next_permutation(power.begin(), power.end()));
}

int bfs(int a, int b, int c) {
    int result = 0;
    queue<Data> q;
    q.emplace(a, b, c);
    visited[a][b][c] = true;
    while (!q.empty()) {
        result++;
        for (int i = 0, size = q.size(); i < size; i++) {
            Data front = q.front();
            q.pop();
            for (vector<int> power: powers) {
                int aa = max(0, front.a - power[0]);
                int bb = max(0, front.b - power[1]);
                int cc = max(0, front.c - power[2]);
                if (aa == 0 && bb == 0 && cc == 0) return result;
                if (!visited[aa][bb][cc]) {
                    visited[aa][bb][cc] = true;
                    q.emplace(aa, bb, cc);
                }
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(3, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    initPower();
    cout << bfs(v[0], v[1], v[2]) << "\n";
    return 0;
}