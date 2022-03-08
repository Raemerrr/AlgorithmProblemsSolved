#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer;
vector<int> v, preSum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    v.assign(N, 0);
    preSum.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (i == 0) {
            preSum[i] = v[i];
        } else {
            preSum[i] = v[i] + preSum[i - 1];
        }
    }
    answer = preSum[K - 1];
    for (int i = K, j = 0; i < N; i++, j++) {
        answer = max(answer, preSum[i] - preSum[j]);
    }
    cout << answer << "\n";
    return 0;
}