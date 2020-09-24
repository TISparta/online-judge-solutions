// Binary Search
// 4
// 07-01-2019

#include <bits/stdc++.h>

using namespace std;

int k;
vector <int> word;

bool check (int width) {
  int nRows = 0, curW;
  int n = word.size();
  for (int i = 0; i < n;) {
    if (word[i] > width) return false;
    nRows++;
    curW = 0;
    while (i < n and curW + word[i] <= width) curW += word[i++];
  }
  return nRows <= k;
}

int main () {
  cin >> k;
  getchar();
  string line, w;
  getline(cin, line);
  for (char& ch: line) if (ch == '-') ch = ' ';
  istringstream token(line);
  while (token >> w) word.push_back(w.size() + 1);
  word.back()--;
  int l = 0, r = line.size();
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) r = m - 1;
    else l = m + 1;
  }
  cout << (check(l) ? l : l + 1) << endl;
  return (0);
}
