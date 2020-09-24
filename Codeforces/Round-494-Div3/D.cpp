// Greedy, Binary Search
// 3
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_BIT = 31;

int cnt[MAX_BIT + 1];

int main () {
  map <int, int> mp;
  for (int bit = 0; bit <= MAX_BIT; bit++) mp[1 << bit] = bit;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[mp[a]]++;
  }
  while (q--) {
    int val;
    cin >> val;
    int ans = 0;
    for (int bit = MAX_BIT; bit >= 0 and val >= 0; bit--) {
      if (cnt[bit] and val >= (1 << bit)) {
        int l = 0, r = cnt[bit];
        while (l != r) {
          int m = (l + r + 1) / 2;
          if (val >= 1LL * m * (1 << bit)) l = m;
          else r = m - 1;
        }
        ans += l;
        val -= 1LL * l * (1 << bit);
      }
    }
    cout << (val == 0 ? ans : - 1) << endl;
  }
  return (0);
}
