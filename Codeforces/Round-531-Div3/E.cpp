/**
 * > Author: TISparta
 * > Date: 09-01-19
 * > Tags: BIT
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

struct BIT {
  int n;
  vector <int> ft;
  BIT () {}
  BIT (int n): n(n) {
    ft.resize(n);
  }
  int get (int pos) {
    int ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos bitand -pos;
    }
    return ret;
  }
  void update(int pos, int val) {
    while (pos < n) {
      ft[pos] += val;
      pos += pos bitand -pos;
    }
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector <int> arr(n + 1);
  BIT ft(n + 100);
  map <int, vector <int>> mp;
  map <int, bool> state;
  long long ways = 1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    mp[arr[i]].push_back(i);
  }
  for (auto pp: mp) {
    bool ok = true;
    int lpos = pp.second.front();
    for (int i = 1; i < pp.second.size(); i++) {
      ok &= (pp.second[i] == lpos + 1);
      lpos = pp.second[i];
    }
    if (not ok) {
      ft.update(pp.second.front(), 1);
      ft.update(pp.second.back() + 1, -1);
      state[pp.first] = false;
    }
    else {
      state[pp.first] = true;
    }
  }
  state[arr[1]] = false;
  for (int i = 1; i <= n; i++) {
    if (ft.get(i) != 0) state[arr[i]] = false;
  }
  for (int i = 2; i <= n; i++) {
    if (arr[i] != arr[i - 1] and (state[arr[i - 1]] or state[arr[i]])) ways = (ways * 2) % MOD;
  }
  cout << ways << endl;
  return (0);
}
