// Tags: Greedy
// Difficulty: 4.0
// Priority: 1
// Date: 18-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    string order = "";
    vi cnt(30, 0);
    for (int i = sz(s) - 1; i >= 0; i--) {
      if (cnt[s[i] -'a'] == 0) order += s[i];
      cnt[s[i] - 'a'] += 1;
    }
    reverse(all(order));
    vi need(30, 0);
    bool ok = true;
    for (int i = 0; i < sz(order); i++) {
      ok &= ((cnt[order[i] - 'a'] % (i + 1)) == 0);
      need[order[i] - 'a'] = cnt[order[i] - 'a'] / (i + 1);
    }
    if (not ok) {
      cout << -1 << '\n';
      continue;
    }
    string ans = "";
    for (char ch: s) {
      ans += ch;
      need[ch - 'a'] -= 1;
      bool die = true;
      for (int i = 0; i < 30; i++) {
        die &= (need[i] == 0);
        ok &= (need[i] >= 0);
      }
      if (die or not ok) break;
    }
    if (not ok) {
      cout << -1 << '\n';
      continue;
    }
    string gg = ans;
    string ss = gg;
    for (char ch: order) {
      string nss = "";
      for (char ch2: ss) if (ch != ch2) nss += ch2;
      ss = nss;
      gg += ss;
    }
    if (gg != s) cout << -1 << '\n';
    else cout << ans << ' ' << order << '\n';
  }
  return (0);
}
