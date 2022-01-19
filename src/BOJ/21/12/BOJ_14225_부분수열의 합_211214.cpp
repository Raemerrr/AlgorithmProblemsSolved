#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 1;
vector<int> v, sumV;

void func(const vector<int> &arr, vector<int> &target, const int idx, const int sum) {
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
    cin >> N;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    func(v, sumV, 0, 0);
    sort(sumV.begin(), sumV.end());
    while (binary_search(sumV.begin(), sumV.end(), answer)) {
        answer++;
    }
    cout << answer << "\n";
    return 0;
}