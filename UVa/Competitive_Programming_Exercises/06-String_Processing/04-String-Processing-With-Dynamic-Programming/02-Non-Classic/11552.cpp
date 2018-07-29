#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e3 + 10, ALPHABET = 30;

int k, memo[MAX_LEN][ALPHABET];
string s;
vector <string> group;

int dp (int id = 0, char last_ch = 'z' + 1) {
  if (id == group.size()) return 0;
  if (~memo[id][last_ch]) return memo[id][last_ch];
  int ret = INT_MAX, pib = 0;
  if (group[id].find(last_ch) != string::npos) {
    pib = -1;
  }
  if (group[id].size() == 1) {
    ret = (int)group[id].size() + pib + dp(id + 1, group[id][0]);
  }
  else {
    for (char ch: group[id]) {
      if (ch != last_ch) {
        ret = min(ret, (int)group[id].size() + pib + dp(id + 1, ch));
      }
    }
  }
  return memo[id][last_ch] = ret;
}

void preprocess () {
  for (int i = 0; i < s.size(); i += k) {
    set <char> st;
    for (int j = i; j < i + k; j++) st.insert(s[j]);
    group.push_back(string(begin(st), end(st)));
  }
}

void clearCase () {
  group.clear();
  memset(memo, -1, sizeof memo);
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    clearCase();
    cin >> k >> s;
    preprocess();
    cout << dp() << endl;
  }
  return (0);
}
