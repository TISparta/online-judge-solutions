// BFS
// 4
// 13-10-2020

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
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  const int INF = 1e9;
  vi dis(n + 1, INF);
  queue <int> q;
  vector <vi> g(n + 1);
  for (int i = 1; i <= n; i++) {
    int u1 = i - a[i];
    int u2 = i + a[i];
    bool add = false;
    if (1 <= u1) {
      g[u1].pb(i);
    }
    if (u2 <= n) {
      g[u2].pb(i);
    }
    if (1 <= u1 and (a[i] % 2) != (a[u1] % 2)) {
      add = true;
    }
    if (u2 <= n and (a[i] % 2) != (a[u2] % 2)) {
      add = true;
    }
    if (add) {
      q.push(i);
      dis[i] = 1;
    }
  }
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (int v: g[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int val = (dis[i] == INF) ? -1 : dis[i];
    cout << val << " \n"[i == n];
  }
  return (0);
}
