#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10, MAX_M = 1e6 + 10, SQRT = 3000;

int n, m, a, b, cnt, root, c[MAX_M], start[MAX_N], finish[MAX_N], arr[2 * MAX_N + 100], level[MAX_N];
int chunk[SQRT];
vector <int> G[MAX_N];

void update (int pos) {
  int c = pos / root;
  chunk[c] = -1;
  for (int k = c * root; k < (c + 1) * root and k < cnt; k++) {
    chunk[c] = max(chunk[c], arr[k]);
  }
}

int processQuery (int val) {
  int l = start[val], r = finish[val];
  int mx = -1;
  while (l % root != 0 and l <= r) {
    mx = max(mx, arr[l]);
    l++;
  }
  if (l % root == 0) {
    while (l + root <= r) {
      mx = max(mx, chunk[l / root]);
      l += root;
    }
  }
  while (l <= r) {
    mx = max(mx, arr[l]);
    l++;
  }
  if (mx >= 0) {
    arr[start[mx]] = arr[finish[mx]] = -1;
    update(start[mx]);
    update(finish[mx]);
  }
  return max(mx, 0);
}

void preprocessChunks () {
  for (int i = 0; i < cnt; i++) {
    int c = i / root;
    chunk[c] = max(chunk[c], arr[i]);
  }
}

void dfs (int u, int p = -1, int l = 0) {
  arr[cnt] = u;
  start[u] = cnt++;
  level[u] = l;
  for (int v: G[u]) if (v != u) dfs(v, u, l + 1);
  arr[cnt] = u;
  finish[u] = cnt++;
}

inline bool cmp (const int& x, const int& y) {
  return level[x] > level[y];
}

long long solve () {
  cnt = 0;
  dfs(0);
  root = sqrt(cnt);
  preprocessChunks();
  sort(c, c + m, cmp);
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    sum += processQuery(c[i]);
  }
  return sum;
}

void generateC () {
  for (int i = 0; i < m; i++) {
    c[i] = (1LL * i * a + b) % n;
  }
}

void readCase () {
  cin >> n >> m >> a >> b;
  for (int i = 1; i < n; i++) {
    int parent;
    cin >> parent;
    G[parent].push_back(i);
  }
}

void clearCase () {
  for (int i = 0; i < n; i++) G[i].clear();
  fill(chunk, chunk + SQRT, -1);
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    clearCase();
    readCase();
    generateC();
    printf("Case #%d: %lld\n", t, solve());
  }
  return (0);
}
