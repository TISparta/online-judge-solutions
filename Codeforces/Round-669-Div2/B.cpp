// Brute Force
// 3
// 08-09-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vpii a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = a[i].first;
    }
    for (int i = 0; i < n; i++) {
      sort(all(a));
      int x = a.back().first;
      cout << a.back().second << " \n"[i == n - 1];
      a.pop_back();
      for (auto& pp: a) {
        pp.first = __gcd(pp.first, x);
      }
    }
  }
  return (0);
}
