// Greedy
// 3
// 03-12-2020

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
  string s;
  cin >> s;
  string ans = "";
  for (char ch: s) {
    if (sz(ans) % 2 == 0 or ans.back() != ch) ans += ch;
  }
  if (sz(ans) & 1) ans.pop_back();
  cout << sz(s) - sz(ans) << '\n';
  cout << ans << '\n';
  return (0);
}
