// DP
// 5.2
// 30-04-2021

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
  vll a(n + 1);
  for (int i = 2; i <= n; i++) cin >> a[i];
  vector <vpll> g(n + 2);
  for (int x = 2; x <= n; x++) {
    ll w1 = a[x];
    int xx = x + a[x];
    if (xx <= 0 or xx > n) {
      g[n + 1].emplace_back(x, w1);
      continue;
    }
    if (xx == 1) continue; // cycle
    ll w2 = a[xx];
    xx = xx - a[xx];
    if (xx <= 0 or xx > n) {
      g[n + 1].emplace_back(x, w1 + w2);
    } else {
      g[xx].emplace_back(x, w1 + w2);
    }
  }
  vll cost(n + 2, -1);
  queue <int> q;
  cost[n + 1] = 0;
  q.push(n + 1);
  // is a DAG
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w]: g[u]) {
      cost[v] = cost[u] + w;
      q.push(v);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    ll x = 1;
    ll y = 0;
    x += i;
    y += i;
    ll w = a[x];
    x -= w;
    y += w;
    if (x <= 0 or x > n) {
      cout << y << '\n';
      continue;
    }
    if (cost[x] == -1) {
      cout << -1 << '\n';
    } else {
      cout << y + cost[x] << '\n';
    }
  }
  return (0);
}
