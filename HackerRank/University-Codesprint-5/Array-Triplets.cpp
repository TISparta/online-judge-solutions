/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : Backtracking
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 17;

typedef long long ll;

int n, arr[MAX_N];
ll sum[5], ans;

void backtrack (int id, int used = 0) {
  if (id == n) {
    if (used != 7) return;
    ans += (sum[0] == sum[1] and sum[1] == sum[2]);
    return;
  }
  for (int i = 0; i < 3; i++) {
    sum[i] += arr[id];
    backtrack(id + 1, used bitor (1 << i));
    sum[i] -= arr[id];
  }
}

int main () {
  cin >> n;
  int limit = 1;
  for (int i = 0; i < n; i++) cin >> arr[i], limit *= 3;
  backtrack(0);
  cout << ans << endl;
  return (0);
}
