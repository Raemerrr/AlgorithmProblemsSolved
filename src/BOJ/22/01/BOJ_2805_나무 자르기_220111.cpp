#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M, lo, hi;
vector<int> v;

bool check(int cut) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (cut < v[i]) sum += v[i] - cut;
    }
    return M <= sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    lo = -1, hi = 1000000001;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}