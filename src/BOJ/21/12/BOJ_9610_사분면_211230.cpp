#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    v.assign(5, 0);
    cin >> N;
    while (N--) {
        int x = 0, y = 0;
        cin >> x >> y;
        if (x > 0 && y > 0) v[0]++;
        else if (x < 0 && y > 0) v[1]++;
        else if (x < 0 && y < 0) v[2]++;
        else if (x > 0 && y < 0) v[3]++;
        else v[4]++;
    }
    cout << "Q1: " << v[0] << "\n";
    cout << "Q2: " << v[1] << "\n";
    cout << "Q3: " << v[2] << "\n";
    cout << "Q4: " << v[3] << "\n";
    cout << "AXIS: " << v[4] << "\n";
    return 0;
}