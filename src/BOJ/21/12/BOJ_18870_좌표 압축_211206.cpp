#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v, vCopy;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    vCopy = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (const int d: vCopy) {
        cout << (lower_bound(v.begin(), v.end(), d) - v.begin()) << " ";
    }
    cout << "\n";
    return 0;
}