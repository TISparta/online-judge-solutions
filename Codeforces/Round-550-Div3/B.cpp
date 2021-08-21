// Tags: Greedy
// Difficulty: 1.5
// Priority: 4
// Date: 31-03-2021

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;

ll get (vector <ll> a, vector <ll> b) {
  ll ret = accumulate(all(a), 0LL) + accumulate(all(b), 0LL);
  int i = 0, j = 0;
  bool flag = true;
  while (true) {
    if (flag) {
      if (i == sz(a)) break;
      ret -= a[i];
      i++;
    } else {
      if (j == sz(b)) break;
      ret -= b[j];
      j++;
    }
    flag = 1 - flag;
  }
  return ret;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <ll> odd, even;
  for (int i = 0; i < n; i++) {
    ll elem;
    cin >> elem;
    if (elem & 1) odd.push_back(elem);
    else even.push_back(elem);
  }
  sort(all(odd));
  sort(all(even));
  reverse(all(odd));
  reverse(all(even));
  cout << min(get(odd, even), get(even, odd)) << endl;
  return (0);
}
