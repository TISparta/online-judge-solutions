// Tags: Bitmasks
// Difficulty: 4.5
// Priority: 3
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
    ll n, m;
    cin >> n >> m;
    if (n > m) {
      cout << 0 << '\n';
      continue;
    }
    ll k = (1LL << 31) - 1;
    for (int bit = 31; bit >= 0; bit--) {
      int nk = k;
      int b = (n >> bit) & 1;
      if (b == 0) nk ^= (1LL << bit);
      if (nk > m) k = nk;
    }
    cout << (k ^ n) << '\n';
  }
  return (0);
}
