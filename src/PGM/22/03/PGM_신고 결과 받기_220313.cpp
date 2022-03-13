#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);;
    vector<int> cnt(id_list.size(), 0);

    // 각 id별 인덱스 부여
    map<string, int> idx;
    for (int i = 0; i < id_list.size(); i++) idx[id_list[i]] = i;

    // 각 id(인덱스)별 신고 내역 정리 - 중복 제거
    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (const string &str: report) {
        stringstream in(str);
        string a, b;
        in >> a >> b;
        v.emplace_back(idx[a], idx[b]);
    }

    // 각 id(인덱스)별 신고 횟수 파악
    for (const auto&[a, b]: v) cnt[b]++;
    // 신고 내역 중 처리된 신고 내역 파악
    for (const auto&[a, b]: v) if (cnt[b] >= k) answer[a]++;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    for (const int d: solution(id_list, report, k)) {
        cout << d << " ";
    }
    cout << "\n";
    return 0;
}