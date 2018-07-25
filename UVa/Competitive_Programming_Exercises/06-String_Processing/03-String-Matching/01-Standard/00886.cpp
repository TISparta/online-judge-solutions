#include <bits/stdc++.h>

using namespace std;

string s;
vector <string> name;
vector <string> number;

void solve () {
  do {
    bool match = false;
    for (int i = 0; i < number.size() and not match; i++)
      if (number[i] == s) cout << s << endl, match = true;
    if (match) continue;
    vector <string> ans;
    for (int i = 0; i < name.size(); i++)
      if (name[i].size() >= s.size() and name[i].substr(0, s.size()) == s)
        ans.push_back(number[i]);
    if (ans.empty()) cout << '0' << endl;
    else {
      cout << ans[0];
      for (int i = 1; i < ans.size(); i++) cout << ' ' << ans[i];
      cout << endl;
    }
  } while (cin >> s);
}

char value (char ch) {
  ch = toupper(ch);
  if (ch <= 'C') return '2';
  if (ch <= 'F') return '3';
  if (ch <= 'I') return '4';
  if (ch <= 'L') return '5';
  if (ch <= 'O') return '6';
  if (ch <= 'S') return '7';
  if (ch <= 'V') return '8';
  return '9';
}

string convert (const char first_ch, const string x) {
  string ret = "";
  ret += value(first_ch);
  for (const char ch: x) ret += value(ch);
  return ret;
}

void readData () {
  string line;
  while (getline(cin, line)) {
    vector <string> word;
    istringstream token(line);
    while (token >> s) word.push_back(s);
    if (word.size() == 1) return;
    name.push_back(convert(word[0][0], word[1]));
    number.push_back(word[2]);
  }
}

int main () {
  readData();
  solve();
  return (0);
}
