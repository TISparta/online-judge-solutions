#include <bits/stdc++.h>

using namespace std;

int n, k, diff;
vector <pair <int, int>> E;
vector <int> W;

void printGraph () {
  cout << E.size() << endl;
  for (int i = 0; i < E.size(); i++) {
    cout << E[i].first << ' ' << E[i].second << ' ' << W[i] << endl;
  }
}

void solve () {
  if (k == 1 or k == 2 or n == 2) {
    diff = 0;
    E.push_back({1, n});
    W.push_back(1);
    return;
  }
  E.push_back({1, n});
  W.push_back(k);
  int v = 1, sum = 0;
  while (v != n) {
    if (k - v == 1) {
      E.push_back({v, n});
      W.push_back(k - v);
      sum = sum + (k - v);
      break;
    }
    E.push_back({v, v + 1});
    W.push_back(k - v);
    sum = sum + (k - v);
    v++;
  }
  diff = sum - k;
}

void clearCase () {
  E.clear();
  W.clear();
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    clearCase();
    cin >> n >> k;
    solve();
    printf("Case #%d: %d\n", t, diff);
    printGraph();
  }
  return (0);
}
