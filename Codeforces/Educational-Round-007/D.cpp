// Tags: Constructive Algorithms
// Difficulty: 5.3
// Priority: 3
// Date: 19-12-2019

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
  int n;
  cin >> n;
  vector <int> ans(2 * n, n);
  int l = 0, r = n;
  int cur = 1;
  while (cur < n) {
    ans[l] = ans[l + n - cur] = cur;
    l++;
    cur++;
    if (cur == n) break;
    ans[r] = ans[r + n - cur] = cur;
    r++;
    cur++;
  }
  n <<= 1;
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
  return (0);
}
