#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
LL N, M, answer;
vector<LL> v, leftV, rightV, leftSum, rightSum;

void func(const vector<LL> &arr, vector<LL> &target, const LL idx, const LL sum) {
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
    cin >> N >> M;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) (i < N / 2 ? leftV : rightV).push_back(v[i]);
    func(leftV, leftSum, 0, 0);
    func(rightV, rightSum, 0, 0);
    sort(leftSum.begin(), leftSum.end());
    for (const int d: rightSum) {
        auto[lo, hi] = equal_range(leftSum.begin(), leftSum.end(), M - d);
        answer += hi - lo;
    }
    cout << (M == 0 ? answer - 1 : answer) << "\n";
    return 0;
}