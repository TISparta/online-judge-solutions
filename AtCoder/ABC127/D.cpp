// Brute Force
// 2
// 09-12-2020

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
  int n, m;
  cin >> n >> m;
  vll a(n);
  for (auto& ai: a) cin >> ai;
  vpii arr(m);
  for (int i = 0; i < m; i++) {
    cin >> arr[i].second >> arr[i].first;
  }
  sort(rall(arr));
  vi b;
  for (auto [ci, bi]: arr) {
    for (int i = 0; i < bi and sz(b) < n; i++) {
      b.pb(ci);
    }
  }
  sort(rall(a));
  int i = n - 1;
  ll sum = accumulate(all(a), 0LL);
  ll ans = sum;
  for (auto bi: b) {
    sum = sum - a[i--] + bi;
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return (0);
}
