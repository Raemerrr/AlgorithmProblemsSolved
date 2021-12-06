#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<string, string>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name, dd, mm, yyyy;
        cin >> name >> dd >> mm >> yyyy;
        dd = string(2 - dd.size(), '0') + dd;
        mm = string(2 - mm.size(), '0') + mm;
        yyyy = string(4 - yyyy.size(), '0') + yyyy;
        v.emplace_back(name, yyyy + mm + dd);
    }
    auto[minIt, maxIt] = minmax_element(v.begin(), v.end(),
                                        [](const pair<string, string> &a, const pair<string, string> &b) {
                                            return a.second < b.second;
                                        });
    cout << (*maxIt).first << "\n" << (*minIt).first << "\n";
    return 0;
}