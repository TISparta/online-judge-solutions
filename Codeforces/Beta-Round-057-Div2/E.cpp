// BIT
// 4
// 11-01-2018

#include <bits/stdc++.h>

using namespace std;

struct BIT {
  int sz = 0;
  vector <int> ft;
  BIT () {}
  BIT (int _sz): sz(_sz + 10) {
    ft.resize(sz, 0);
  }
  void update (int pos, const int val) {
    while (pos < sz) {
      ft[pos] += val;
      pos += pos bitand -pos;
    }
  }
  int get (int pos) {
    int ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos bitand -pos;
    }
    return ret;
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, cnt = 0;
  map <int, int> mp;
  cin >> n;
  vector <int> arr(n + 1);
  BIT left(n), right(n);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    mp[arr[i]] = 1;
  }
  for (pair <const int, int>& pp: mp) pp.second = ++cnt;
  for (int i = 1; i <= n; i++) {
    arr[i] = mp[arr[i]];
    right.update(arr[i], 1);
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    ans += 1LL * (left.get(n) - left.get(arr[i])) * right.get(arr[i] - 1);
    left.update(arr[i], 1);
    right.update(arr[i], -1);
  }
  cout << ans << endl;
  return (0);
}
