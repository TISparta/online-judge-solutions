// DP
// 2
// 09-09-2020

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
  vll min_pref(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    min_pref[i] = a[i] + min_pref[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    min_pref[i] = min(min_pref[i], min_pref[i - 1]);
  }
  ll acc = 0;
  ll ans = LLONG_MIN;
  for (int i = 1; i <= n; i++) {
    acc += a[i];
    ans = max(ans, acc - min_pref[i - 1]);
  }
  cout << ans << '\n';
  return (0);
}
