#include <bits/stdc++.h>

using namespace std;

int main () {
  int T, N, Pi;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i <= N; i++) cin >> Pi;
    cout << "Case #" << t << ": ";
    if (N & 1) {
      cout << 1 << endl;
      cout << "0.0" << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  return (0);
}
