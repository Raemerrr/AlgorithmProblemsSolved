#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 3; i++) {
        int num = 0;
        cin >> num;
        s.insert(num);
    }
    for (const int d: s) cout << d << " ";
    cout << "\n";
    return 0;
}