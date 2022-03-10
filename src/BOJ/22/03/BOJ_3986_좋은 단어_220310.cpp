#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;

bool solution(string &str) {
    while (!str.empty()) {
        bool flag = false;
        for (int i = 0, size = str.size(); i < size - 1; i++) {
            if (str[i] == str[i + 1]) {
                flag = true;
                str.erase(i, 2);
                break;
            }
        }
        if (!flag) break;
    }
    return str.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        answer += (solution(str) ? 1 : 0);
    }
    cout << answer << "\n";
    return 0;
}