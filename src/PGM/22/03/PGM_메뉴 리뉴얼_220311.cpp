#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool isInclude(const string &pattern, const string &str) {
    for (const char c: pattern) if (str.find(c) == string::npos) return false;
    return true;
}

vector<char> create(vector<string> &orders) {
    vector<char> alpha;
    for (const string &str: orders) {
        for (const char c: str) {
            alpha.push_back(c);
        }
    }
    sort(alpha.begin(), alpha.end());
    alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
    return alpha;
}

map<string, int> count(const vector<string> &orders, const vector<int> &course, const vector<char> &alpha) {
    map<string, int> m;
    for (const int c: course) {
        vector<int> select;
        for (int i = 0; i < alpha.size() - c; i++) select.push_back(0);
        for (int i = 0; i < c; i++) select.push_back(1);
        do {
            string pattern;
            for (int i = 0; i < select.size(); i++) {
                if (select[i] == 1) pattern.push_back(alpha[i]);
            }
            for (const string &o: orders) {
                if (o.size() >= c) {
                    if (isInclude(pattern, o)) {
                        m[pattern]++;
                    }
                }
            }
        } while (next_permutation(select.begin(), select.end()));
    }
    return m;
}

vector<pair<string, int>> order(const map<string, int> &m) {
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    return v;
}

vector<string> getAnswer(vector<pair<string, int>> &v) {
    vector<string> answer;
    reverse(v.begin(), v.end());
    map<int, int> maxMap;
    while (!v.empty()) {
        pair<string, int> back = v.back();
        int _course = back.first.size();
        v.pop_back();
        if (!maxMap.count(_course)) {
            if (back.second > 1) {
                maxMap[_course] = back.second;
                answer.push_back(back.first);
            }
        } else {
            if (back.second == maxMap[_course]) answer.push_back(back.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<char> alpha = create(orders);
    map<string, int> m = count(orders, course, alpha);
    vector<pair<string, int>> v = order(m);
    return getAnswer(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //vector<string> orders{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    //vector<int> course{2, 3, 4};
    vector<string> orders{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course{2, 3, 5};
    for (const string &d: solution(orders, course)) {
        cout << d << " ";
    }
    cout << "\n";
    return 0;
}