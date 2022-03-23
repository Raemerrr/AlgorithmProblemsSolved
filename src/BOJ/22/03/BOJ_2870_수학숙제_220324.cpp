#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        string str = "";
        cin >> str;
        while (!str.empty()) {
            // 임시 값
            string temp = "";
            // 문자 제거
            while (!str.empty() && isalpha(str.back())) str.pop_back();
            // 숫자의 경우 temp 저장
            while (!str.empty() && isdigit(str.back())) {
                temp = str.back() + temp;
                str.pop_back();
            }
            while (!temp.empty() && temp.size() > 1 && temp.front() == '0') {
                // '0'으로 시작하는 문자열 앞에서부터 지우기
                temp.erase(temp.begin());
            }
            if (!temp.empty()) v.push_back(temp);
        }
    }
    sort(v.begin(), v.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for (const string &d: v) cout << d << "\n";
    return 0;
}