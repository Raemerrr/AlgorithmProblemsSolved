#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(9, 0);
    for (int i = 0; i < 9; i++) cin >> v[i];
    sort(v.begin(), v.end());
    do {
        int sum = 0;
        for (int i = 0; i < 7; i++) sum += v[i];
        if (sum == 100) break;
    } while (next_permutation(v.begin(), v.end()));
    for (int i = 0; i < 7; i++) cout << v[i] << "\n";
    return 0;
}