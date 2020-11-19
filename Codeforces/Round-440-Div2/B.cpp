// Brute Force
// 2
// 19-11-2020

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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int& ai: a) cin >> ai;
  vi mn1(n);
  vi mn2(n);
  mn1[0] = a[0];
  for (int i = 1; i < n; i++) mn1[i] = min(a[i], mn1[i - 1]);
  mn2[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) mn2[i] = min(a[i], mn2[i + 1]);
  if (k == 1 or n == 1) {
    cout << *min_element(all(a)) << '\n';
    return (0);
  }
  if (k > 2) {
    cout << *max_element(all(a)) << '\n';
    return (0);
  }
  int ans = INT_MIN;
  for (int i = 0; i + 1 < n; i++) {
    ans = max(ans, max(mn1[i], mn2[i + 1]));
  }
  cout << ans << '\n';
  return (0);
}
