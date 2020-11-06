// Greedy
// 3
// 05-11-2020

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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  auto substr = [&] (string s, string t) {
    for (int i = 0; i <= sz(t) - sz(s); i++) {
      string x = t.substr(i, sz(s));
      if (x == s) return true;
    }
    return false;
  };
  sort(all(s), [&] (string a, string b) {
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    return a < b;
  });
  for (int i = 1; i < n; i++) {
    if (not substr(s[i - 1], s[i])) {
      cout << "NO\n";
      return (0);
    }
  }
  cout << "YES\n";
  for (auto si: s) cout << si << '\n';
  return (0);
}
