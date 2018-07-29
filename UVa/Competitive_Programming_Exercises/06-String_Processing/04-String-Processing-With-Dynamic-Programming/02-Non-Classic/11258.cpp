#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_VAL = 1LL << 31, MAX_N = 200 + 10;

string s;
int id[MAX_N];
ll num[MAX_N][MAX_N], memo[MAX_N];

ll dp (int i) {
  if (i == s.size()) return 0;
  if (~memo[i]) return memo[i];
  ll ret = 0;
  for (int k = i; k < id[i]; k++)
    ret = max(ret, num[i][k] + dp(k + 1));
  return memo[i] = ret;
}

void preprocess () {
  for (int i = 0; i < s.size(); i++) {
    memo[i] = -1;
    ll val = 0;
    id[i] = s.size();
    for (int j = i; j < s.size(); j++) {
      val = val * 10 + (s[j] - '0');
      if (val < MAX_VAL) num[i][j] = val;
      else {
        id[i] = j;
        break;
      }
    }
  }
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> s;
    preprocess();
    cout << dp(0) << endl;
  }
  return (0);
}
