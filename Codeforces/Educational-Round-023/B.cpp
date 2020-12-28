// Combinatorics
// 3
// 27-12-2020

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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  int x = 0;
  while (3 + x < n and a[2] == a[3 + x]) x += 1;
  if (a[1] != a[2]) {
    cout << 1 + x << '\n';
  } else {
    if (a[0] != a[1]) {
      // comb(2 + x, 2) = comb(2 + x, x) = (2 + x) * (1 + x) / 2
      cout << 1LL * (2 + x) * (1 + x) / 2 << '\n';
    } else {
      // comb(3 + x, 3) = comb(3 + x, x) = (3 + x) * (2 + x) * (1 + x) / 6
      cout << 1LL * (3 + x) * (2 + x) * (1 + x) / 6 << '\n';
    }
  }
  return (0);
}
