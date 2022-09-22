#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, S;
vector<int> leftV, rightV;
vector<LL> leftSum, rightSum;
LL answer;

void proc(const vector<int> &v, vector<LL> &sumV, const int idx, const LL sum) {
    if (idx == v.size()) {
        sumV.emplace_back(sum);
        return;
    }
    proc(v, sumV, idx + 1, sum);
    proc(v, sumV, idx + 1, sum + v[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        ((i < N / 2) ? leftV : rightV).push_back(num);
    }
    proc(leftV, leftSum, 0, 0);
    proc(rightV, rightSum, 0, 0);
    sort(leftSum.begin(), leftSum.end());
    for (const LL d: rightSum) {
        auto[lo, hi] = equal_range(leftSum.begin(), leftSum.end(), S - d);
        answer += hi - lo;
    }
    cout << ((S == 0) ? answer - 1 : answer) << "\n";
    return 0;
}