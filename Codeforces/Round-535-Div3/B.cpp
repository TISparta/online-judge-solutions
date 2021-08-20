// Tags: Brute Force
// Difficulty: 1.5
// Priority: 5
// Date: 24-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 10;

vector <int> D[MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < MAX_N; i++) for (int j = i; j < MAX_N; j += i) D[j].push_back(i);
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(begin(arr), end(arr));
  for (int x: arr) {
    for (int y: arr) {
      vector <int> tmp = D[x];
      for (int k: D[y]) tmp.push_back(k);
      sort(begin(tmp), end(tmp));
      if (tmp == arr) {
        cout << x << ' ' << y << endl;
        return (0);
      }
    }
  }
  return (0);
}
