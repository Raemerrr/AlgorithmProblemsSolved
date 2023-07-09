#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str, pattern, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> pattern;
	for (int i = 0; i < str.size(); i++) {
		answer += str[i];
		if (str[i] == pattern[pattern.size() - 1] && answer.size() >= pattern.size())
		{
			bool flag = true;
			for (int j = 0; j < pattern.size(); j++) {
				if (answer[answer.size() - 1 - j] != pattern[pattern.size() - 1 - j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int j = 0; j < pattern.size(); j++) { answer.pop_back(); }
			}
		}
	}
	cout << (answer.empty() ? "FRULA" : answer) << "\n";
	return 0;
}