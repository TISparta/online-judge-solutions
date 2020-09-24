// Ad-Hoc
// 1
// 17-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  long long s1 = 0, s2 = 0, s3 = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s1 += x;
  }
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    s2 += x;
  }
  for (int i = 0; i < n - 2; i++) {
    int x;
    cin >> x;
    s3 += x;
  }
  cout << s1 - s2 << endl;
  cout << s2 - s3 << endl;
  return (0);
}
