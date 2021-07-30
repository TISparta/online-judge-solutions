// Tags: Math
// Difficulty: 1.0
// Priority: 4
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
    int n;
    cin >> n;
    int d = n % 3;
    if (d == 0) {
      cout << n / 3 << ' ' << n / 3 << '\n';
    } else if (d == 1) {
      int x = (n - 1) / 3;
      cout << x + 1 << ' ' << x << '\n';
    } else {
      int x = (n - 2) / 3;
      cout << x << ' ' << x + 1 << '\n';
    }
  }
  return (0);
}
