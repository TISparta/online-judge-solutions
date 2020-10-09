// Math
// 3
// 08-09-2020

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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vi ans;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == a[i + 1]) {
        ans.pb(a[i]);
        ans.pb(a[i + 1]);
      } else {
        ans.pb(0);
      }
    }
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); i++) cout << ans[i] <<  ' '; cout << endl;
  }
  return (0);
}
