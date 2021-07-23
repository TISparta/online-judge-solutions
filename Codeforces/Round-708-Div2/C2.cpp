// Tags: Math
// Difficulty: 3.5
// Priority: 3
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
  /*
  for (int x = 1; x <= 9; x++) {
    for (int y = 1; y <= 9; y++) {
      int z = 10 - x - y;
      if (z < 1) continue;
      int lcm = 1;
      while (true) {
        if (lcm % x == 0 and lcm % y == 0 and lcm % z == 0) break;
        lcm += 1;
      }
      if (lcm <= 5) cout << x << ' ' << y << ' ' << z << endl;
    }
  }
  return (0);
  */
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    while (k > 3) {
      cout << 1 << ' ';
      k -= 1;
      n -= 1;
    }
    if (n & 1) {
      cout << 1 << ' ' << (n - 1) / 2 << ' ' << (n - 1) / 2 << '\n';
    } else if (n % 4 == 0) {
      cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
    } else {
      cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << endl;
    }
  }
  return (0);
}
