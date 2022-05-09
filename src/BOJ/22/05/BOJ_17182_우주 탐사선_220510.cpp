#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, K, answer = INF;
vector<vector<int>> board;

void floyd() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][k] != INF && board[k][j] != INF) {
                    board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (i == j) {
                board[i][j] = INF;
            }
        }
    }
    floyd();
    vector<int> combi;
    for (int i = 0; i < N; i++) {
        if (i != K) {
            combi.push_back(i);
        }
    }
    do {
        int sum = 0;
        int _prev = K;
        for (const int _next: combi) {
            sum += board[_prev][_next];
            _prev = _next;
        }
        answer = min(answer, sum);
    } while (next_permutation(combi.begin(), combi.end()));
    cout << answer << "\n";
    return 0;
}