// Tags: Constructive Algorithms
// Difficulty: 3.0
// Priority: 5
// Date: 18-06-2021

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
    vi h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(all(h));
    if (h[0] == h[1]) {
      h.pb(h[0]);
      h.erase(begin(h));
    } else if (h[n - 1] == h[n - 2]) {
      h.insert(begin(h), h[n - 1]);
      h.pop_back();
    } else {
      pii mn(INT_MAX, INT_MAX);
      for (int i = 0; i + 1 < n; i++) {
        mn = min(mn, pii(h[i + 1] - h[i], i));
      }
      int x = mn.second;
      vi z;
      z.pb(h[x]);
      for (int i = x + 2; i < n; i++) {
        z.pb(h[i]);
      }
      for (int i = 0; i < x; i++) {
        z.pb(h[i]);
      }
      z.pb(h[x + 1]);
      h = z;
    }
    for (int i = 0; i < n; i++) cout << h[i] << " \n"[i + 1 == n];
  }
  return (0);
}
