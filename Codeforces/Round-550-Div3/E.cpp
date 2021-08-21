// Tags: Implementation
// Difficulty: 4.0
// Priority: 4
// Date: 31-03-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;

void subt (vector <int> a, vector <int> b, vector <int>& c) {
  for (int i = sz(a) - 1; i >= 0; i--) {
    while (a[i] < b[i]) {
      assert(i != 0);
      a[i] += 26;
      a[i - 1]--;
    }
    c[i] = a[i] - b[i];
  }
}

void div2 (vector <int> a, vector <int>& ret) {
  int carry = 0;
  for (int i = 0; i < sz(a); i++) {
    int val = a[i] + carry;
    ret[i] = (val / 2) % 26;
    carry = 26 * (val % 2);
  }
}

void sum (vector <int> a, vector <int> b, vector <int>& c) {
  int carry = 0;
  for (int i = sz(a) - 1; i >= 0; i--) {
    int val = a[i] + b[i] + carry;
    c[i] = val % 26;
    carry = val / 26;
  }
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  vector <int> n1(k), n2(k);
  for (int i = 0; i < k; i++) {
    n1[i] = s[i] - 'a';
    n2[i] = t[i] - 'a';
  }
  vector <int> ret(k), res(k), ans(k);
  subt(n2, n1, ret);
  div2(ret, res);
  sum(n1, res, ans);
  for (int elem: ans) cout << char('a' + elem); cout << endl;
  return (0);
}
