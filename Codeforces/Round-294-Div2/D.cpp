// Cummulative Sums
// 3
// 17-01-2019

#include <bits/stdc++.h>

using namespace std;

int W[30];
map <long long, int> frec[30];

int main () {
  for (char ch = 'a'; ch <= 'z'; ch++) cin >> W[ch - 'a'];
  long long ans = 0LL, sum = 0LL;
  string s;
  cin >> s;
  for (char ch: s) {
    int id = ch - 'a';
    ans += frec[id][sum - W[id]];
    frec[id][sum]++;
    sum += W[id];
  }
  cout << ans << endl;
  return (0);
}
