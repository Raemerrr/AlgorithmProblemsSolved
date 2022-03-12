#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, C, answer;
vector<LL> leftSum, rightSum;
vector<int> leftV, rightV, v;

void func(int idx, const vector<int> &arr, vector<LL> &sumV, LL sum) {
    if (idx == arr.size()) {
        sumV.push_back(sum);
        return;
    }
    func(idx + 1, arr, sumV, sum);
    func(idx + 1, arr, sumV, sum + arr[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> C;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        (i < N / 2 ? leftV : rightV).push_back(v[i]);
    }
    if (N == 1) {
        cout << 1 + (v[0] <= C) << "\n";
        return 0;
    }
    func(0, leftV, leftSum, 0);
    func(0, rightV, rightSum, 0);
    sort(leftSum.begin(), leftSum.end());
    for (const int d: rightSum) {
        answer += upper_bound(leftSum.begin(), leftSum.end(), C - d) - leftSum.begin();
    }
    cout << answer << "\n";
    return 0;
}