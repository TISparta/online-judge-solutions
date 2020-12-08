// Greedy
// 3
// 04-12-2020

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 0; i + 1 < n; i++) {
      sum += abs(a[i] - a[i + 1]);
    }
    ll ans = min(sum - abs(a[0] - a[1]), sum - abs(a[n - 1] - a[n - 2]));
    for (int i = 1; i + 1 < n; i++) {
      ll sub = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
      ans = min(ans, sum - sub + abs(a[i - 1] - a[i + 1]));
    }
    cout << ans << '\n';
  }
  return (0);
}
