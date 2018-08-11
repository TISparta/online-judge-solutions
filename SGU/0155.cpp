#include <bits/stdc++.h>

using namespace std;

const int NOT_FOUND = INT_MAX;

typedef int ktype;
typedef int ptype;

struct Tnode {

    ktype key;
    ptype priority;
    Tnode* left = 0;
    Tnode* right = 0;

    Tnode(ktype key_, ptype priority_):
        key(key_),
        priority(priority_) {}
    ~Tnode() {
        delete left;
        delete right;
    }

};

const int MAX_N = 5e4, MAX_A = 3e4;

typedef Tnode* pnode;
int mp[2 * MAX_A + 10], ans_1[MAX_N + 10], ans_2[MAX_N + 10], ans_3[MAX_N + 10];

namespace Treap {

    void split(pnode root, pnode& left, pnode& right, ktype key) {
        if (not root) {
            left = right = 0;
            return;
        }
        if (key < root -> key) split(root -> left, left, root -> left, key), right = root;
        else split(root -> right, root -> right, right, key), left = root;
    }

    void insert(pnode& root, pnode new_node) {
        if (!root) root = new_node;
        else if (root -> priority > new_node -> priority)
            split(root, new_node -> left, new_node -> right, new_node -> key), root = new_node;
        else insert(new_node -> key < root -> key ? root -> left : root -> right, new_node);
    }

    inline int order(const pnode& root) {
        return root ? mp[root -> key] : 0;
    }

    void inorder(const pnode& root, const int parent = 0) {
        if (root) {
            int idx = mp[root -> key] - 1;
            ans_1[idx] = parent;
            ans_2[idx] = order(root -> left);
            ans_3[idx] = order(root -> right);
            inorder(root -> left, mp[root -> key]);
            inorder(root -> right, mp[root -> key]);
        }
    }

}

int N;
pnode treap;
vector <pair <int, int>> arr;

inline bool cmp(const pair <int, int>& X, const pair <int, int>& Y) {
    return X.second > Y.second;
}

int main() {
    scanf("%d", &N);
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        arr[i].first += MAX_A;
        mp[arr[i].first] = i + 1;
    }
    sort(begin(arr), end(arr), cmp);
    for (int i = 0; i < N; i++) {
        Treap::insert(treap, new Tnode(arr[i].first, arr[i].second));
    }
    puts("YES");
    Treap::inorder(treap);
    for (int i = 0; i < N; i++)
        printf("%d %d %d\n", ans_1[i], ans_2[i], ans_3[i]);
    return (0);
}
