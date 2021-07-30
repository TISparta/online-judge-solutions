// Tags: Greedy
// Difficulty: 1.7
// Priority: 1
// Date: 29-07-2021

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
    ll ans = a[0] * a[1];
    for (int i = 1; i + 1 < n; i++) ans = max(ans, a[i] * a[i + 1]);
    cout << ans << '\n';
  }
  return (0);
}
