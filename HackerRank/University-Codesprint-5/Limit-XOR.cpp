/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : Trie
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5, MAX_D = 33;

ll n, k, xor_sum, arr[MAX_N + 10], ans;

struct Trie {
  ll cnt = 0;
  Trie *l = 0, *r = 0;
  Trie () {}
  ~Trie () {
    delete l;
    delete r;
  }
};

void insert (Trie* root, ll add) {
  for (int pos = MAX_D; pos >= 0; pos--) {
    int p = (add >> pos) bitand 1;
    if (p == 0) {
      if (not root -> l) root -> l = new Trie();
      root = root -> l;
    }
    else {
      if (not root -> r) root -> r = new Trie();
      root = root -> r;
    }
    root -> cnt += 1;
  }
}

ll add (Trie* root) {
  if (not root) return 0LL;
  return root -> cnt;
}

ll get (Trie* root, ll sum, ll k) {
  ll ret = 0;
  for (int pos = MAX_D; pos >= 0; pos--) {
    if (not root) return ret;
    int p = (sum >> pos) bitand 1;
    int q = (k >> pos) bitand 1;
    if (q) {
      if (p) ret += add(root -> r), root = root -> l;
      else ret += add(root -> l), root = root -> r;
    }
    else {
      if (p) root = root -> r;
      else root = root -> l;
    }
  }
  return ret;
}

int main () {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  Trie* root = new Trie();
  insert(root, 0);
  for (int i = 0; i < n; i++) {
    xor_sum ^= arr[i];
    ans += get(root, xor_sum, k);
    insert(root, xor_sum);
  }
  cout << ans << endl;
  return (0);
}
