#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 50 + 5, MAX_P = 12 + 5, MAX_MASK = (1 << 12) + 1, INF = 1e7;

int v, e, p, pos[MAX_P], dis[MAX_V][MAX_V], save[MAX_P], memo[MAX_V][MAX_MASK][MAX_P];

int dp (int u, int taken, int id) {
  if (id == p) return -dis[u][0];
  if (memo[u][taken][id] != INF) return memo[u][taken][id];
  int ret = dp(u, taken, id + 1);
  for (int dvd = 0; dvd < p; dvd++) {
    if ((taken >> dvd) & 1) {
      int val = save[dvd] - dis[u][pos[dvd]] + dp(pos[dvd], taken xor (1 << dvd), id + 1);
      ret = max(ret, val);
    }
  }
  return memo[u][taken][id] = ret;
}

void FloydWarshall () {
  for (int u = 0; u <= v; u++) dis[u][u] = 0;
  for (int k = 0; k <= v; k++)
    for (int i = 0; i <= v; i++)
      for (int j = 0; j <= v; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void readCase () {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int u, v, w, a, b;
    scanf("%d %d %d.%d", &u, &v, &a, &b);
    w = a * 100 + b;
    dis[u][v] = min(dis[u][v], w);
    dis[v][u] = min(dis[v][u], w);
  }
  cin >> p;
  for (int i = 0; i < p; i++) {
    int _pos, a, b;
    scanf("%d %d.%d", &_pos, &a, &b);
    pos[i] = _pos;
    save[i] = a * 100 + b;
  }
}

void clearCase () {
  fill(dis[0], dis[MAX_V], INF);
  for (int i = 0; i < MAX_V; i++)
    for (int j = 0; j < MAX_MASK; j++)
      for (int k = 0; k < MAX_P; k++)
        memo[i][j][k] = INF;
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    clearCase();
    readCase();
    FloydWarshall();
    int ans = dp(0, (1 << p) - 1, 0);
    if (ans <= 0) puts("Don't leave the house");
    else printf("Daniel can save $%d.%.2d\n", ans / 100, ans % 100);
  }
  return (0);
}
