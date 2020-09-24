// Sorting
// 3
// 09-09-2020

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
  int n, x;
  cin >> n >> x;
  vpii a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(all(a));
  for (int i = 1; i <= n; i++) {
    int xx = x - a[i].first;
    int l = 1, r = n;
    while (l < r) {
      if (a[l].first + a[r].first < xx) {
        l += 1;
      } else if (a[l].first + a[r].first > xx) {
        r -= 1;
      } else if (a[l].second != a[i].second and a[r].second != a[i].second) {
        cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << '\n';
        return (0);
      } else {
        l += 1;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return (0);
}
