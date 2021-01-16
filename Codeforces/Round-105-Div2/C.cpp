// Greedy
// 3
// 16-01-2021

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
  int n, a, b;
  cin >> n >> a >> b;
  const int N = 50000;
  vi t(n);
  auto check = [&] (vi t) {
    ll sum = t[0];
    ll mx = t[0];
    ll x = 0, y = 0;
    for (int i = 1; i < n; i++) {
      if (sum < t[i]) y += 1;
      else if (mx < t[i]) x += 1;
      sum += t[i];
      mx = max(mx, 1LL * t[i]);
    }
    return int(x == a and y == b);
  };
  auto go1 = [&] () {
    t = vi(n, 1);
    ll sum = 1;
    for (int i = 0; i < b; i++) {
      t[i + 1] = 1 + sum;
      sum += t[i + 1];
      if (t[i + 1] > N) return 0;
    }
    for (int i = 0; i < a; i++) {
      t[b + 1 + i] = t[b + i] + 1;
      if (t[b + 1 + i] > N) return 0;
    }
    return check(t);
  };
  auto go2 = [&] () {
    t = vi(n, 1);
    ll sum = 1;
    for (int i = 0; i < a; i++) {
      t[i + 1] = 1 + t[i];
      sum += t[i + 1];
      if (t[i + 1] > N) return 0;
    }
    for (int i = 0; i < b; i++) {
      t[a + 1 + i] = sum + 1;
      sum += t[a + 1 + i];
      if (t[a + 1 + i] > N) return 0;
    }
    if (b == 0) {
      for (int i = n - 1; i > 0; i--) t[i] = t[i - 1];
    }
    return check(t);
  };
  if (go1() or go2()) {
    for (auto xi: t) cout << xi << ' '; cout << '\n';
  } else {
    cout << -1 << '\n';
  }
  return (0);
}
