// BIT
// 6
// 17-08-2020

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

ll solve (int m, vi& a) {
  int n = sz(a);
  vi x(n);
  vi ft(2 * n + 10, 0);
  auto get = [&] (int pos) {
    ll ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  };
  auto update = [&] (int pos, int val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  };
  int sum = 0;
  int offset = n + 2;
  ll ret = 0;
  update(offset + 0, 1);
  for (int i = 0; i < n; i++) {
    if (a[i] < m) sum -= 1;
    else sum += 1;
    ret += get(offset + sum - 1);
    update(offset + sum, 1);
  }
  return ret;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int& ai: a) cin >> ai;
  cout << solve(m, a) - solve(m + 1, a) << '\n';
  return (0);
}
