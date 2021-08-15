// Tags: Number Theory
// Difficulty: 5.0
// Priority: 4
// Date: 02-08-2021

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  const int N = 5e6 + 1;
  vector <ll> primes_cnt(N, 0);
  for (int i = 2; i < N; i++) {
    if (primes_cnt[i] == 0) {
      for (ll j = i; j < N; j *= i) {
        for (int k = j; k < N; k += j) {
          primes_cnt[k]++;
        }
      }
    }
  }
  vector <ll> fact_primes_cnt(N, 0);
  for (int i = 2; i < N; i++) fact_primes_cnt[i] = primes_cnt[i] + fact_primes_cnt[i - 1];
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    cout << fact_primes_cnt[a] - fact_primes_cnt[b] << '\n';
  }
  return (0);
}
