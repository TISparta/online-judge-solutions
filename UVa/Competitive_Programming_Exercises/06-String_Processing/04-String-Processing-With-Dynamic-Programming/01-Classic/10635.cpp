#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 250 * 250 + 10;

int n, n1, n2, idx[MAX_N], L[MAX_N];
vector <int> arr;

int lis () {
  int ret = 0;
  for (int i = 0; i < arr.size(); i++) {
    int pos = lower_bound(L, L + ret, arr[i]) - L;
    L[pos] = arr[i];
    if (pos + 1 > ret) ret = pos + 1;
  }
  return ret;
}

void readCase () {
  cin >> n >> n1 >> n2;
  for (int i = 0, a; i <= n1; i++) {
    cin >> a;
    idx[a] = i;
  }
  for (int i = 0, a; i <= n2; i++) {
    cin >> a;
    if (~idx[a]) arr.push_back(idx[a]);
  }
}

void clearCase () {
  arr.clear();
  memset(idx, -1, sizeof idx);
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    clearCase();
    readCase();
    printf("Case %d: %d\n", t, lis());
  }
}
