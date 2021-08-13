// Tags: Greedy
// Difficulty: 1.6
// Priority: 4
// Date: 17-11-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

void die () {
  cout << -1 << '\n';
  exit (0);
}

const int max_val = 1e6 + 10;

int pos[max_val];
int _next[max_val];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <int> arr(n);
  memset(pos, -1, sizeof pos);
  memset(_next, -1, sizeof _next);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > 0) {
      int val = arr[i];
      if (pos[val] != -1) die();
      pos[val] = i;
    } else {
      int val = -arr[i];
      if (pos[val] == -1) die();
      _next[pos[val]] = i;
      pos[val] = -1;
    }
  }
  for (int i = 0; i < max_val; i++) if (pos[i] != -1) die();
  memset(pos, 0, sizeof pos);
  int ans = 0;
  for (int i = 0; i < n; ) {
    int j = _next[i];
    for (int k = i; k <= j; k++) {
      if (arr[k] < 0) continue;
      j = max(j, _next[k]);
      if (pos[arr[k]]) die();
      pos[arr[k]]++;
    }
    for (int k = i; k <= j; k++) {
      if (arr[k] < 0) continue;
      pos[arr[k]] = 0;
    }
    _next[i] = j;
    ans++;
    i = j + 1;
  }
  cout << ans << '\n';
  int cur = 0;
  for (int i = 0; i < ans; i++) {
    int n = _next[cur];
    cout << n - cur + 1 << " \n"[i == ans - 1];
    cur = n + 1;
  }
  return (0);
}
