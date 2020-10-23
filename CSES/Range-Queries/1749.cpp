// BIT
// 3
// 21-09-2020

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
  vi ft(n + 10, 0);
  auto update = [&] (int pos, int val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  };
  auto sum = [&] (int pos) {
    ll ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  };
  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, 1);
  }
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    int l = 1, r = n;
    while (l != r) {
      int m = (l + r) >> 1;
      if (sum(m) >= p) r = m;
      else l = m + 1;
    }
    cout << a[l] << " \n"[i == n];
    update(l, -1);
  }
  return (0);
}
