/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tags : Treap
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int NOT_FOUND = INT_MAX;

typedef int ktype;
typedef int ptype;

struct Tnode {

    ktype key, max_key;
    ptype priority;
    Tnode* left = 0;
    Tnode* right = 0;
    size_t sz;

    Tnode(ktype key_):
        key(key_),
        priority(rand()),
        sz(1) {}
    ~Tnode() {
        delete left;
        delete right;
    }

};

typedef Tnode* pnode;

namespace Treap {

    void setSeed() {
        srand(time(0));
    }

    inline size_t len(pnode& root) {
        return root ? root -> sz : 0;
    }

    inline void updateLen(pnode& root) {
        if (root) root -> sz = len(root -> left) + len(root -> right) + 1;
    }

    inline ktype maxKey(pnode& root) {
        return root ? root -> max_key : INT_MIN;
    }

    inline ktype max(const ktype& a, const ktype& b) {
        return a > b ? a : b;
    }

    inline void updateMaxKey(pnode& root) {
        if (root) {
            root -> max_key = max(root -> key, max(maxKey(root -> left), maxKey(root -> right)));
        }
    }

    void splitImplicit(pnode root, pnode& left, pnode& right, ktype key) {
        if (not root) {
            left = right = 0;
            return;
        }
        int sz = len(root -> left);
        if (key <= sz)
            splitImplicit(root -> left, left, root -> left, key), right = root;
        else
            splitImplicit(root -> right, root -> right, right, key - sz - 1), left = root;
        updateLen(root);
        updateMaxKey(root);
    }

    void merge(pnode& root, pnode left, pnode right) {
        if (not left) root = right;
        else if (not right) root = left;
        else if (left -> priority > right -> priority)
            merge(left -> right, left -> right, right), root = left;
        else
            merge(right -> left, left, right -> left), root = right;
        updateLen(root);
        updateMaxKey(root);
    }

    void add(pnode& root, pnode new_node, ktype pos) {
        pnode l, r;
        splitImplicit(root, l, r, pos - 1);
        merge(l, l, new_node);
        merge(root, l, r);
    }

    ktype maxValue(pnode& root, ktype x, ktype y) {
        pnode l, m, r;
        splitImplicit(root, l, r, x - 1);
        splitImplicit(r, m, r, y - x + 1);
        int ret = m -> max_key;
        merge(r, m, r);
        merge(root, l, r);
        return ret;
    }

}

int N, x, y;
char ch;
pnode treap;

int main() {
    scanf("%d\n", &N);
    while (N--) {
        scanf("%c %d %d\n", &ch, &x, &y);
        if (ch == 'A') Treap::add(treap, new Tnode(x), y);
        else printf("%d\n", Treap::maxValue(treap, x, y));
    }
    return (0);
}
