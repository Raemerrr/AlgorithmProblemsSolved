#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;
map<string, int> nameMap;
map<int, string> indexMap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string name; cin >> name;
        nameMap[name] = i;
        indexMap[i] = name;
    }
    while (M--) {
        string str; cin >> str;
        if (nameMap.count(str)) cout << nameMap[str] << "\n";
        else cout << indexMap[stoi(str)] << "\n";
    }
    return 0;
}