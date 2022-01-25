#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, S;
LL answer;
vector<int> v, leftV, rightV;
vector<LL> leftSum, rightSum;


void proc(const vector<int> &arr, vector<LL> &sumV, int idx, LL sum) {
    if (idx == arr.size()) {
        sumV.push_back(sum);
        return;
    }
    proc(arr, sumV, idx + 1, sum);
    proc(arr, sumV, idx + 1, sum + arr[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        ((i < N / 2) ? leftV : rightV).push_back(v[i]);
    }
    proc(leftV, leftSum, 0, 0);
    proc(rightV, rightSum, 0, 0);
    sort(leftSum.begin(), leftSum.end());
    for (const int d: rightSum) {
        auto[lo, hi] = equal_range(leftSum.begin(), leftSum.end(), S - d);
        answer += hi - lo;
    }
    cout << (S == 0 ? answer - 1 : answer) << "\n";
    return 0;
}