/**
 * > Author : TISparta
 * > Date : 16-08-18
 * > Tags : Segment Tree
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int LEN = 3e4 + 10;

struct Node {
  int open = 0, closed = 0, correct = 0;
  Node () {};
}NIL;

struct STree {
  int l, r;
  Node state = Node();
  STree *left, *right;
  STree () {}
  STree (int _l, int _r): l(_l), r(_r) {}
};

int tc, n;
char s[LEN];

Node merge (Node left, Node right) {
  Node ret;
  int correct = min(left.open, right.closed);
  ret.correct = left.correct + right.correct + correct;
  ret.open = left.open + right.open - correct;
  ret.closed = left.closed + right.closed - correct;
  return ret;
}

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> state.open = s[l] == '(';
    root -> state.closed = s[r] == ')';
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  root -> state = merge(root -> left -> state, root -> right -> state);
}

void update (STree*& root, const int pos) {
  if (pos == root -> l and root -> r == pos) {
    swap(root -> state.open, root -> state.closed);
    return;
  }
  if (pos <= root -> left -> r) update(root -> left, pos);
  else update(root -> right, pos);
  root -> state = merge(root -> left -> state, root -> right -> state);
}

void processQueries () {
  STree *tree;
  build(tree, 0, n - 1);
  int q;
  scanf("%d", &q);
  printf("Test %d:\n", ++tc);
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k == 0) puts((tree -> state.correct == n / 2) and (n % 2 == 0) ? "YES" : "NO");
    else update(tree, k - 1);
  }
}

bool readCase () {
  if (scanf("%d\n", &n) != 1) return false;
  scanf("%s", s);
  return true;
}

int main () {
  while (readCase()) processQueries();
  return (0);
}
