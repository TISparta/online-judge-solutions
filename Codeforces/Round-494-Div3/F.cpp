/**
 * > Author: TISparta
 * > Date: 23-12-19
 * > Tags: Hashing, Z function, Brute Force
 * > Difficulty: 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int P = 231, MOD = 1e9 + 9, MAX_LEN = 1e5 + 1000;

inline int add (int a, int b) { return (1LL * a + b) % MOD; }
inline int mul (int a, int b) { return (1LL * a * b) % MOD; }

int p[MAX_LEN];

int getHash (const string& x) {
  int H = 0;
  for (int i = 0; i < x.size(); i++) H = add(H, mul(p[i], x[i] - 'a' + 1));
  return H;
}

int main () {
  p[0] = 1;
  for (int i = 1; i < MAX_LEN; i++) p[i] = mul(p[i - 1], P);
  int n;
  cin >> n;
  vector <vector <int>> arr(n + 1);
  vector <int> len(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    arr[i].push_back(getHash(x));
    len[i] = len[i - 1] + x.size();
  }
  for (int i = n - 1; i >= 1; i--) {
    arr[i].insert(end(arr[i]), begin(arr[i + 1]), end(arr[i + 1]));
  }
  int ans = len[n] + n - 1;
  for (int i = 1; i <= n; i++) {
    vector <int> t = arr[i];
    t.push_back(-1);
    t.insert(end(t), begin(arr[1]), end(arr[1])); 
    int m = t.size();
    vector <int> z(m);
    for (int it = 0, l = 0, r = 0; it < m; it++) {
      if (it <= r) z[it] = min(r - it + 1, z[it - l]);
      while (it + z[it] < m and t[z[it]] == t[it + z[it]]) z[it]++;
      if (it + z[it] - 1 > r) l = it, r = it + z[it] - 1;
    }
    int offset = arr[i].size();
    for (int k = 1; i + k <= n; k++) {
      int j = i + k;
      int segments = 1;
      while (j <= n) {
        if (z[offset + j] >= k) {
          j += k;
          segments++;
        }
        else j++;
      }
      if (segments >= 2) {
        int val = len[n] + n - 1;
        val -= segments * (len[i + k - 1] - len[i - 1] + k - 1);
        val += segments * k;
        ans = min(ans, val);
      }
    }
  }
  cout << ans << endl;
  return (0);
}
