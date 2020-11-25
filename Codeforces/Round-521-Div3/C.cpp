// Brute Force
// 3
// 24-11-2020

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
  vi a(n + 1);
  ll sum = 0;
  map <ll, vi> pos;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].pb(i);
    sum += a[i];
  }
  vi ans;
  for (int j = 1; j <= n; j++) {
    // sum - ai - aj = aj
    // sum - 2 aj = ai
    ll ai = sum - 2 * a[j];
    if (pos.count(ai) == 0) continue;
    if (ai == a[j] and sz(pos[ai]) <= 1) continue;
    for (int x: pos[ai]) ans.pb(x);
    pos[ai].clear();
  }
  cout << sz(ans) << '\n';
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
  return (0);
}
