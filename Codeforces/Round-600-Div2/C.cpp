// Tags: Cummulative Sums
// Difficulty: 3.5
// Priority: 3
// Date: 17-11-2021

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  vector <ll> ans(n);
  vector <ll> acc(n, 0);
  ans[0] = a[0];
  acc[0] = a[0];
  for (int i = 1; i < m; i++) ans[i] = ans[i - 1] + a[i], acc[i] = a[i];
  for (int i = m; i < n; i++) {
    acc[i] = a[i] + acc[i - m];
    ans[i] = ans[i - 1] + acc[i];
//    for (int k = i - m; k >= 0; k -= m) ans[i] += a[k];
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
  return (0);
}
