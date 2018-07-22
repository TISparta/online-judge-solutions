/**
 * > Author: TISparta
 * > Date: 14-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    ll N, K, V;
    cin >> N >> K >> V;
    deque <string> A(N);
    vector <bool> vis(N, false);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll lambda = N / __gcd(N, K);
    V = (V - 1) % lambda;
    int id = 0;
    while (V--) id = (id + K) % N;
    cout << "Case #" << t << ':';
    for (int i = 0; i < K; i++) vis[(id + i) % N] = true;
    for (int i = 0; i < N; i++) if (vis[i]) cout << ' ' << A[i];
    cout << endl;
  }
  return (0);
}
