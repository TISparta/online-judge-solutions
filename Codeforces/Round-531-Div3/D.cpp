// Greedy
// 3
// 09-01-2019

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map <int, int> frec;

int main () {
  cin >> n >> s;
  for (int i = 0; i < n; i++) frec[s[i]]++;
  if (frec['0'] < n / 3) {
    for (int i = 0; i < n; i++) {
      if (frec[s[i]] > n / 3) {
        if ('0' != s[i] and frec['0'] < n / 3) {
          frec[s[i]]--;
          frec['0']++;
          s[i] = '0';
        }
      }
    }
  }
  if (frec['1'] < n / 3) {
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') cnt0++;
      if (s[i] == '2' and frec['2'] > n / 3 and frec['1'] < n / 3) {
        frec['2']--;
        frec['1']++;
        s[i] = '1';
      }
      if (s[i] == '0' and cnt0 > n / 3 and frec['1'] < n / 3) {
        frec['1']++;
        frec['0']--;
        s[i] = '1';
        cnt0--;
      }
    }
  }
  if (frec['2'] < n / 3) {
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '2' and frec['2'] < n / 3 and frec[s[i]] > n / 3) {
        frec[s[i]]--;
        frec['2']++;
        s[i] = '2';
      }
    }
  }
  cout << s << endl;
  return (0);
}
