#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(N, vector<char>(M, '.'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0, k = M - 1; j < M / 2; j++, k--) {
            if (v[i][j] != '.') {
                v[i][k] = v[i][j];
            }
            if (v[i][k] != '.') {
                v[i][j] = v[i][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}