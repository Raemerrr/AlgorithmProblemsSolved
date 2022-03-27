#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, num = 665;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (0 < N) {
        num++;
        if (to_string(num).find("666") != string::npos) N--;
    }
    cout << num << "\n";
    return 0;
}