// Brute Force
// 2.0
// 21-04-2021

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
    vll l(n);
    l[0] = a[0];
    for (int i = 1; i < n; i++) l[i] = l[i - 1] ^ a[i];
    bool ok = false;
    for (int i = 0; i + 1 < n; i++) {
      int x = l[i];
      int r = i + 1;
      bool gaa = false;
      int last = i;
      while (r < n) {
        if ((l[r] ^ l[last]) == x) {
          gaa = true;
          while (r + 1 < n and a[r + 1] == 0) r += 1;
          last = r;
          r += 1;
        } else {
          gaa = false;
          r += 1;
        }
      }
      ok |= (gaa and (r == n));
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return (0);
}
