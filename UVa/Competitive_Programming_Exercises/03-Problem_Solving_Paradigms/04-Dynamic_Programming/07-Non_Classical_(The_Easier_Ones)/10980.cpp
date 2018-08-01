#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 10, MAX_BUY = 10000 + 10, INF = 1e7;

int tc, buy, memo[MAX_N][MAX_BUY];
vector <pair <int, int>> arr;

int dp (int id, int cnt) {
  if (id == arr.size()) return buy <= cnt ? 0 : INF;
  if (cnt < MAX_BUY and ~memo[id][cnt]) return memo[id][cnt];
  int ret = INF, get = -1;
  do {
    get++;
    ret = min(ret, get * arr[id].second + dp(id + 1, cnt + get * arr[id].first));
  } while (get * arr[id].first <= buy);
  if (cnt < MAX_BUY) memo[id][cnt] = ret;
  return ret;
}

bool solve () {
  int a, b, m, ct;
  if (scanf("%d.%d %d", &a, &b, &m) != 3) return false;
  arr.clear();
  arr.push_back({1, a * 100 + b});
  for (int i = 0; i < m; i++) {
    scanf("%d %d.%d", &ct, &a, &b);
    arr.push_back({ct, a * 100 + b});
  }
  getchar();
  string line;
  getline(cin, line);
  istringstream token(line);
  printf("Case %d:\n", ++tc);
  while (token >> buy) {
    for (int i = 0; i < arr.size(); i++)
      for (int j = 0; j < MAX_BUY; j++)
        memo[i][j] = -1;
    int res = dp(0, 0);
    printf("Buy %d for $%d.%.2d\n", buy, res / 100, res % 100);
  }
  return true;
}

int main () {
  while (solve()) ;
  return (0);
}
