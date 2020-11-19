// Math
// 3
// 29-08-2020

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
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    if (n < 4) {
      cout << -1 << '\n';
      continue;
    }
    if (n % 4 == 0) {
      cout << n / 4 << '\n';
    } else if (n % 4 == 1) {
      if (n < 9) {
        cout << -1 << '\n';
      } else {
        cout << 1 + (n - 9) / 4 << '\n';
      }
    } else if (n % 4 == 2) {
      cout << 1 + (n - 6) / 4 << '\n';
    } else {
      if (n < 15) {
        cout << -1 << '\n';
      } else {
        cout << 2 + (n - 15) / 4 << '\n';
      }
    }
  }
  return (0);
}
