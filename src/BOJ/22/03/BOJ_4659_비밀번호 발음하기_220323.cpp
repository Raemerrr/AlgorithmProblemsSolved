#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string input;
vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

bool check1(const string &str) {
    bool result = false;
    for (const char vowel: vowels) {
        if (str.find(vowel) != string::npos) {
            result = true;
            break;
        }
    }
    return result;
}

bool check1(const char c) {
    bool result = false;
    for (const char vowel: vowels) {
        if (vowel == c) {
            result = true;
            break;
        }
    }
    return result;
}

bool check2(const string &str) {
    bool result = true;
    int limit = 3;
    if (limit <= str.size()) {
        for (int i = 0; i < str.size() - limit + 1; i++) {
            map<bool, int> m;
            for (int j = i; j < i + limit; j++) {
                bool b = check1(str[j]);
                m[b]++;
            }
            if (limit <= m[true] || limit <= m[false]) {
                result = false;
                break;
            }
        }
    }
    return result;
}

bool check3(const string &str) {
    bool result = true;
    int limit = 2;
    if (limit <= str.size()) {
        for (int i = 0; i < str.size() - limit + 1; i++) {
            if (str[i] == str[i + 1] && !(str[i] == 'e' || str[i] == 'o')) {
                result = false;
                break;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> input) {
        if (input == "end") break;
        if (check1(input) && check2(input) && check3(input)) {
            cout << "<" << input << "> is acceptable.\n";
        } else {
            cout << "<" << input << "> is not acceptable.\n";
        }
    }
    return 0;
}