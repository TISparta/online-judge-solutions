#include <bits/stdc++.h>

using namespace std;

const int W_DEL = 1, W_INS = 1, W_SUB = 1;

const int MAX_LEN = 80 + 10;

string s1, s2;
int dp[MAX_LEN][MAX_LEN];

struct Move {
  char move, ch;
  int pos;
  Move () {}
  Move (char move_, char ch_, int pos_): move(move_), ch(ch_), pos(pos_) {}
};

void stringAlignment () {
  int m = s1.size(), n = s2.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0) dp[0][j] = j * W_INS;
      else if (j == 0) dp[i][j] = i * W_DEL;
      else if (s1[j - 1] == s2[i - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min(dp[i - 1][j - 1] + W_SUB, min(dp[i - 1][j] + W_DEL, dp[i][j - 1] + W_INS));
    }
  }
  int i = n, j = m;
  vector <Move> ans;
  while (i or j) {
    if (i and j and s1[j - 1] == s2[i - 1]) i--, j--;
    else if (i and j and dp[i - 1][j - 1] + W_SUB == dp[i][j]) {
      ans.push_back(Move('C', s2[i - 1], i));
      i--, j--;
    }
    else if (i and dp[i - 1][j] + W_DEL == dp[i][j]) {
      ans.push_back(Move('I', s2[i - 1], i));
      i--;
    }
    else if (j and dp[i][j - 1] + W_INS == dp[i][j]) {
      ans.push_back(Move('D', s1[j - 1], j));
      j--;
    }
  }
  reverse(begin(ans), end(ans));
  int cnt_i = 0, cnt_d = 0;
  cout << dp[n][m] << endl;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i].move == 'D') ans[i].pos = ans[i].pos + cnt_i - cnt_d;
    cout << i + 1 << ' ';
    if (ans[i].move == 'D') cout << "Delete " << ans[i].pos << endl;
    if (ans[i].move == 'I') cout << "Insert " << ans[i].pos << ',' << ans[i].ch << endl;
    if (ans[i].move == 'C') cout << "Replace " << ans[i].pos << ',' << ans[i].ch << endl;
    if (ans[i].move == 'I') cnt_i++;
    if (ans[i].move == 'D') cnt_d++;
  }
}

int main () {
  bool first = true;
  while (getline(cin, s1) and getline(cin, s2)) {
    if (not first) puts("");
    stringAlignment();
    first = false;
  }
  return (0);
}
