#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


typedef long long LL;
int N, S;
vector<int> v, leftV, rightV;
vector<LL> leftSum, rightSum;
LL answer;

void proc(const vector<int> &arr, int index, LL sum, vector<LL> &sumV) {
    if (index == arr.size()) {
        sumV.push_back(sum);
        return;
    }
    proc(arr, index + 1, sum, sumV);
    proc(arr, index + 1, sum + arr[index], sumV);
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
    proc(leftV, 0, 0, leftSum);
    proc(rightV, 0, 0, rightSum);
    sort(leftSum.begin(), leftSum.end());
    for (const LL d: rightSum) {
        auto[lo, hi] = equal_range(leftSum.begin(), leftSum.end(), S - d);
        answer += hi - lo;
    }
    cout << (S == 0 ? answer - 1 : answer) << "\n";
    return 0;
}