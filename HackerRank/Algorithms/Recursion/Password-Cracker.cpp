/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: DP
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int n;
string password;
vector <string> word, answer, formed;
unordered_map <string, bool> memo;

void print () {
  cout << answer[0];
  for (int i = 1; i < answer.size(); i++) cout << ' ' << answer[i];
  cout << endl;
}

bool dp (int it = 0) {
  if (it == password.size()) {
    answer = formed;
    return true;
  }
  string str = password.substr(it);
  if (memo.count(str)) return memo[str];
  bool ret = false;
  for (int i = 0; not ret and i < n; i++)
    if (it + word[i].size() <= password.size() and password.substr(it, word[i].size()) == word[i]) {
      formed.push_back(word[i]);
      ret |= dp(it + word[i].size());
      formed.pop_back();
    }
  return memo[str] = ret;
}

void readCase () {
  cin >> n;
  word.resize(n);
  for (int i = 0; i < n; i++) cin >> word[i];
  cin >> password;
}

inline void initCase () {
  memo.clear();
  answer = {"WRONG", "PASSWORD"};
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    initCase();
    readCase();
    dp();
    print();
  }
  return (0);
}
