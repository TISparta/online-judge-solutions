// Tags: Implementation
// Difficulty: 1.5
// Priority: 1
// Date: 17-03-2021

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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vi used(n, 0);
    vi ans;
    int pos = 0;
    for (int i = 0; i < n; i++) {
      int where = -1;
      for (int j = 0; j < n; j++) {
        if (a[j] == i) where = j;
      }
      if (where == -1) break;
      used[where] = 1;
      ans.pb(i);
    }
    for (int i = 0; i < n; i++) {
      if (used[i] == 0) ans.pb(a[i]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return (0);
}
