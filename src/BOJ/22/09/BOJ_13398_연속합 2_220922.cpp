#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = INT32_MIN;
vector<int> v, leftSum, rightSum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, 0);
    leftSum.assign(N, 0);
    rightSum.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0, j = N - 1; i < N; i++, j--) {
        if (i == 0) {
            leftSum[i] = v[i];
            rightSum[j] = v[j];
        } else {
            leftSum[i] = (v[i] < v[i] + leftSum[i - 1]) ? v[i] + leftSum[i - 1] : v[i];
            rightSum[j] = (v[j] < v[j] + rightSum[j + 1]) ? v[j] + rightSum[j + 1] : v[j];
        }
        answer = max(answer, leftSum[i]);
    }
    for (int i = 1; i < N - 1; i++) answer = max(answer, leftSum[i - 1] + rightSum[i + 1]);
    cout << answer << "\n";
    return 0;
}