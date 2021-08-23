// Tags: Constructive Algorithms
// Difficulty: 3.0
// Priority: 5
// Date: 07-01-2019

#include <bits/stdc++.h>

using namespace std;

void print (string s, vector <int> frec) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 0) continue;
    while (frec[i]--) cout << s[i];
  }
  cout << endl;
}

int main () {
  string s;
  cin >> s;
  vector <int> frec(int(s.size()), 1);
  int sum = 0, n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '?' or s[i] == '*') frec[i] = 0;
    else sum++;
  }
  int k;
  cin >> k;
  if (sum == k) print(s, frec);
  else if (sum < k) {
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*' and ~last) {
        frec[last] += k - sum;
        sum = k;
        break;
      }
      if (s[i] != '?' and s[i] != '*') {
        last = i;
      }
    }
    if (sum == k) print(s, frec);
    else puts("Impossible");
  }
  else {
    int last = -1;
    for (int i = 0; i < n; i++) {
      if ((s[i] == '?' or s[i] == '*') and ~last) {
        frec[last] = 0;
        sum--;
        if (sum == k) break;
      }
      if (s[i] != '?' and s[i] != '*') last = i;
    }
    if (sum == k) print(s, frec);
    else puts("Impossible");
  }
  return (0);
}
