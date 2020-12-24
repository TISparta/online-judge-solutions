// Implementation
// 5
// 02-08-2020

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int n, a[MAX_N];
set <pair <int, int>> st;
map <int, pair <int, int>> Left, Right;

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  pair <int, int> prev(-1, -1);
  for (int l = 0; l < n; ) {
    int r = l;
    while (r + 1 < n and a[l] == a[r + 1]) r++;
    pair <int, int> cur(-(r - l + 1), l);
    st.insert(cur);
    Left[l] = prev;
    l = r + 1;
    prev = cur;
  }
  prev = {-1, -1};
  for (int r = n - 1; r >= 0; ) {
    int l = r;
    while (0 <= l - 1 and a[l - 1] == a[r]) l--;
    pair <int, int> cur(-(r - l + 1), l);
    Right[l] = prev;
    r = l - 1;
    prev = cur;
  }
  int ans = 0;
  pair <int, int> none(-1, -1);
  while (not st.empty()) {
    ans++;
    auto pp = *begin(st);
    st.erase(begin(st));
    auto x = Left[pp.second];
    auto y = Right[pp.second];
    Right[x.second] = y;
    Left[y.second] = x;
    if (x != none and y != none and a[x.second] == a[y.second]) {
      st.erase(x);
      st.erase(y);
      Right[x.second] = Right[y.second];
      pair <int, int> qq(x.first + y.first, x.second);
      st.insert(qq);
      Right[Left[x.second].second] = qq;
      Left[Right[x.second].second] = qq;
    }
  }
  printf("%d\n", ans);
  return (0);
}
