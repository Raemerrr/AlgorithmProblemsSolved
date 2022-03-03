#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int N, S;
vector<int> leftV, rightV;
vector<LL> leftSum, rightSum;
LL answer;

void func(const vector<int> &arr, vector<LL> &sumArr, int idx, LL sum) {
    if (idx == arr.size()) {
        sumArr.push_back(sum);
        return;
    }
    func(arr, sumArr, idx + 1, sum);
    func(arr, sumArr, idx + 1, sum + arr[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        (i < N / 2 ? leftV : rightV).push_back(num);
    }
    func(leftV, leftSum, 0, 0);
    func(rightV, rightSum, 0, 0);
    sort(leftSum.begin(), leftSum.end());
    for (const LL &d: rightSum) {
        auto[lo, hi] = equal_range(leftSum.begin(), leftSum.end(), S - d);
        answer += hi - lo;
    }
    cout << (S == 0 ? answer - 1 : answer) << "\n";
    return 0;
}