// Greedy
// 3
// 05-08-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vi w(n);
    for (int&x: w) cin >> x;
    sort(all(w));
    vi frec(n + 1);
    for (int x: w) frec[x]++;
    int ans = 0;
    for (int s = 2; s <= 2 * n; s++) {
      vi take;
      for (int i = 1; i <= n; i++) {
        int j = s - i;
        if (not (1 <= j and j <= n)) continue;
        if (i != j) {
          while (frec[i] >= 1 and frec[j] >= 1) {
            take.pb(i);
            take.pb(j);
            frec[i] -= 1;
            frec[j] -= 1;
          }
        } else {
          while (frec[i] >= 2) {
            take.pb(i);
            take.pb(i);
            frec[i] -= 2;
          }
        }
      }
      ans = max(ans, sz(take) / 2);
      for (int x: take) frec[x]++;
    }
    cout << ans << '\n';
  }
  return (0);
}
