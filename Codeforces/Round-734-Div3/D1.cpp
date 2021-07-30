// Tags: Constructive Algorithms
// Difficulty: 4.0
// Priority: 3
// Date: 23-07-2021

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
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 1) {
      if (k == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    if (n % 2 == 0) {
      int mx = n * (m / 2);
      if (k % 2 == 0 and k <= mx) {
        // putting horizontals from the left
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      int m2 = m / 2;
      int mx = n * (m / 2);
      if (k < m2 or ((k - m2) & 1) or k > mx) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
  return (0);
}
