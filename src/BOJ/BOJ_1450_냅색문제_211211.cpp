#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
vector<LL> v, leftV, rightV, leftSum, rightSum;
LL N, C, answer;

void func(const vector<LL> &arr, vector<LL> &target, int idx, LL sum) {
    if (idx == arr.size()) {
        target.push_back(sum);
        return;
    }
    func(arr, target, idx + 1, sum);
    func(arr, target, idx + 1, sum + arr[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> C;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        ((i < N / 2) ? leftV : rightV).push_back(v[i]);
    }
    if (N == 1) {
        cout << 1 + (v[0] <= C) << "\n";
        return 0;
    }
    func(leftV, leftSum, 0, 0);
    func(rightV, rightSum, 0, 0);
    sort(leftSum.begin(), leftSum.end());
    for (const LL d: rightSum) {
        answer += upper_bound(leftSum.begin(), leftSum.end(), C - d) - leftSum.begin();
    }
    cout << answer << "\n";
    return 0;
}