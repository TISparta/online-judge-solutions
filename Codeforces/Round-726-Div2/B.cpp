// Tags: Constructive Algorithms
// Difficulty: 1.7
// Priority: 3
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
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    ll ans = 0;
    ll r1, r2;
    if (r - 1 >= n - r) {
      r1 = 1, r2 = n;
    } else {
      r2 = n, r1 = 1;
    }
    ll c1, c2;
    if (c - 1 >= m - c) {
      c1 = 1, c2 = m;
    } else {
      c2 = m, c1 = 1;
    }
    cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
  }
  return (0);
}
