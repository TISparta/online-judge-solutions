// Ad-Hoc
// 2
// 20-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    sum1 += x;
  }
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    sum2 += x;
  }
  int cnt = (sum1 + 4) / 5 + (sum2 + 9) / 10;
  int n;
  cin >> n;
  puts(cnt <= n ? "YES" : "NO");
  return (0);
}
