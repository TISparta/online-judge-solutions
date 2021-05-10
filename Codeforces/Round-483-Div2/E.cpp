// Tags: DP, BFS
// Difficulty: 5.3
// Priority: 4
// Date: 09-05-2021

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

const int N = 2000 + 1;
const int MASK = 10000;
const int INF = 1 << 14;

bool vis[N][10][MASK];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  auto get = [&] (int mask, int floor) {
    vi z(4);
    for (int i = 3; i >= 0; i--) {
      z[i] = mask % 10;
      mask /= 10;
    }
    int pos = -1;
    for (int i = 0; i < 4; i++) if (z[i] == floor) pos = i;
    if (pos == -1) return make_pair(false, -1);
    z[pos] = 0;
    sort(rall(z));
    int nmask = 0;
    int p = 1;
    for (int i = 3; i >= 0; i--) {
      nmask += p * z[i];
      p *= 10;
    }
    return make_pair(true, nmask);
  };
  auto add = [&] (int mask, int floor) {
    vi z(4);
    for (int i = 3; i >= 0; i--) {
      z[i] = mask % 10;
      mask /= 10;
    }
    z[3] = floor;
    sort(rall(z));
    int nmask = 0;
    int p = 1;
    for (int i = 3; i >= 0; i--) {
      nmask += p * z[i];
      p *= 10;
    }
    return nmask;
  };
  queue <tuple <int, int, int, int>> q;
  q.emplace(0, 1, 0, 0);
  vis[0][1][0] = 1;
  while (not q.empty()) {
    auto [who, floor, mask, cost] = q.front();
    q.pop();
    if (who == n and mask == 0) {
      cout << cost << '\n';
      return (0);
    }
    if (floor + 1 <= 9 and not vis[who][floor + 1][mask]) {
      vis[who][floor + 1][mask] = 1;
      q.emplace(who, floor + 1, mask, cost + 1);
    }
    if (1 <= floor - 1 and not vis[who][floor - 1][mask]) {
      vis[who][floor - 1][mask] = 1;
      q.emplace(who, floor - 1, mask, cost + 1);
    }
    auto [ok, nmask] = get(mask, floor);
    if (ok and not vis[who][floor][nmask]) {
      vis[who][floor][nmask] = 1;
      q.emplace(who, floor, nmask, cost + 1);
    }
    if (who < n and a[who] == floor and (mask % 10 == 0)) {
      int nmask = add(mask, b[who]);
      if (not vis[who + 1][floor][nmask]) {
        vis[who + 1][floor][nmask] = 1;
        q.emplace(who + 1, floor, nmask, cost + 1);
      }
    }
  }
  assert(1 == 0);
  return (0);
}
