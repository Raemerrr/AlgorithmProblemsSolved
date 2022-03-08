#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<char, int> m;
string answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        m[str[0]]++;
    }
    for (const pair<char, int> &d: m) {
        if (d.second >= 5) answer += d.first;
    }
    cout << (answer.empty() ? "PREDAJA" : answer) << "\n";
    return 0;
}