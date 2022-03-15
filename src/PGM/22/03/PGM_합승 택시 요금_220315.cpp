#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    const int INF = 987654321;
    int answer = INF;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> node(n, vector<int>(n, 0));
    for (const vector<int> &d: fares) {
        //양방향 연결
        node[d[0] - 1][d[1] - 1] = d[2];
        node[d[1] - 1][d[0] - 1] = d[2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                dp[i][j] = (node[i][j] > 0) ? node[i][j] : INF;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    //각자 갔을 경우
    answer = (dp[s - 1][b - 1] < INF && dp[s - 1][a - 1] < INF) ? dp[s - 1][b - 1] + dp[s - 1][a - 1] : INF;
    for (int i = 0; i < n; i++) {
        if (i == s - 1 || dp[s - 1][i] >= INF || dp[i][b - 1] >= INF || dp[i][a - 1] >= INF) continue;
        int temp = (dp[s - 1][i] + dp[i][b - 1] + dp[i][a - 1]);
        answer = min(temp, answer);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 6, s = 4, a = 6, b = 2;
    vector<vector<int>> fares{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    cout << solution(n, s, a, b, fares) << "\n";
    return 0;
}