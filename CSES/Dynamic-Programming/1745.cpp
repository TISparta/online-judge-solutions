// DP
// 2
// 13-09-2020

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
  vector <bool> can(1000010, false);
  can[0] = true;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = sz(can) - x - 1; j >= 0; j--) {
      if (not can[j]) continue;
      can[j + x] = true;
    }
  }
  vi ans;
  for (int i = 1; i < sz(can); i++) {
    if (can[i]) ans.pb(i);
  }
  cout << sz(ans) << '\n';
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
  return (0);
}
