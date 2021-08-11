// Tags: Brute Force
// Difficulty: 5.0
// Priority: 4
// Date: 30-07-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

void test () {
  int n;
  cin >> n;
  string s(n, ' ');
  function <void(int)> backtrack = [&] (int pos) {
    if (pos == n) {
      for (int i = 1; i < n; i++) if (s[i] == s[i - 1]) return;
      for (int i = 1; i + 1 < n; i++) if (s[i - 1] == s[i + 1]) return;
      cout << s << '\n';
      return;
    }
    for (char ch: {'a', 'b', 'c'}) {
      s[pos] = ch;
      backtrack(pos + 1);
    }
  };
  backtrack(0);
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  //test();
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector <vi> cnt(3, vi(n + 1));
  for (char ch = 'a'; ch <= 'c'; ch++) {
    for (int i = 1; i <= n; i++) {
      cnt[ch - 'a'][i] = (s[i - 1] == ch);
      if (i >= 3) cnt[ch - 'a'][i] += cnt[ch - 'a'][i - 3];
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << '\n';
      continue;
    }
    if (l + 1 == r) {
      int cost = (s[l - 1] == s[l]) ? 1 : 0;
      cout << cost << '\n';
      continue;
    }
    vi perm = {0, 1, 2};
    int ans = INT_MAX;
    do {
      int cost = 0;
      for (int i = 0; i < 3; i++) {
        int from = l + i;
        int x = (r - from) / 3;
        int to = from + 3 * x;
        int have = 1 + (to - from) / 3;
        int good = cnt[perm[i]][to] - cnt[perm[i]][max(0, from - 3)];
        cost = cost + (have - good);
      }
      ans = min(ans, cost);
    } while (next_permutation(all(perm)));
    cout << ans << '\n';
  }
  return (0);
}
