/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tags : Mo algorithm, LCA
 * > Difficulty : 6 / 10
 */

// Playing with pointers :v

#include <bits/stdc++.h>

using namespace std;

int V, Q, BLOCK_SIZE;

struct Tree {
    Tree() {}
    ~Tree() {}
    int timer = 0; 
    vector <int> *W, *depth, *start, *finish, *arr, *father;
    vector <vector <int>> *ancestor;
    vector <vector <int>> *Adj;
    unordered_map <int, int> *order;
    void readWeights() {
        W = new vector <int> (V + 1);
        order = new unordered_map <int, int>;
        for (int i = 1, ct = 1, w_i; i <= V; i++) {
            cin >> w_i;
            if (order -> find(w_i) == order -> end()) (*order)[w_i] = ct++;
            (*W)[i] = (*order)[w_i];
        }
        delete order;
    }
    void readGraph() {
        Adj = new vector <vector <int>> (V + 1);
        for (int i = 1, u, v; i < V; i++) {
            cin >> u >> v;
            (*Adj)[u].emplace_back(v);
            (*Adj)[v].emplace_back(u);
        }
    }
    void dfs(int u, int parent) {
        arr -> emplace_back(0);
        (*start)[u] = timer;
        (*arr)[timer] = u;
        timer++;
        (*father)[u] = parent;
        for (const int& v : (*Adj)[u]) {
            if (v != parent) {
                (*depth)[v] = (*depth)[u] + 1;
                dfs(v, u);
            }
        }
        arr -> emplace_back(0);
        (*finish)[u] = timer;
        (*arr)[timer] = u;
        timer++;
    }
    void processLCA() {
        for (int i = 1; i <= V; i++) (*ancestor)[i][0] = (*father)[i];
        for (int j = 1; (1 << j) <= V; j++)
            for (int i = 1; i <= V; i++)
                if (~(*ancestor)[i][j - 1])
                    (*ancestor)[i][j] = (*ancestor)[(*ancestor)[i][j - 1]][j - 1];
    }
    void build() {
        depth = new vector <int> (V + 1, 0);
        start = new vector <int> (V + 1);
        finish = new vector <int> (V + 1);
        arr = new vector <int>;
        father = new vector <int> (V + 1, -1);
        ancestor = new vector <vector <int>> (V + 1, vector <int> (static_cast<int>(log2(V + 1)) + 2, -1));
        dfs(1, -1);
        processLCA();
    }
    int getLCA(int u, int v) {
        int log = 1;
        if ((*depth)[u] < (*depth)[v]) swap(u, v);
        while ((1 << log) <= (*depth)[u]) log++;
        log--;
        for (int i = log; i >= 0; i--)
            if ((*depth)[u] - (1 << i) >= (*depth)[v]) u = (*ancestor)[u][i];
        if (u == v) return u;
        for (int i = log; i >= 0; i--)
            if (~(*ancestor)[u][i] and (*ancestor)[u][i] != (*ancestor)[v][i]) {
                u = (*ancestor)[u][i];
                v = (*ancestor)[v][i];
            }
        return (*father)[u];
    }
    inline int getStart(const int& u) {
        return (*start)[u];
    }
    inline int getFinish(const int& u) {
        return (*finish)[u];
    }
    inline int getNode(const int& pos) {
        return (*arr)[pos];
    }
    inline int getW(const int& u) {
        return (*W)[u];
    }
};

struct Query {
    int left, right, lca, id;
    bool rollback;
    Query() {};
    Query(const int& L, const int& R, const int P, const int& i, const int& flag):
        left(L), right(R), lca(P), id(i), rollback(flag) {}
    bool operator < (const Query& other) {
        int this_block = left / BLOCK_SIZE;
        int other_block = other.left / BLOCK_SIZE;
        if (this_block != other_block) return this_block < other_block;
        return right < other.right;
    }
};

Tree* G;
vector <Query> *query;
vector <int> *answers, *frec;
vector <bool> *vis;
int current_answer = 0;

namespace Solver {
    void visit(const int& pos) {
        int u = G -> getNode(pos);
        int w = G -> getW(u);
        if ((*vis)[u]) {
            (*frec)[w]--;
            if ((*frec)[w] == 0) current_answer--;
        }
        else {
            (*frec)[w]++;
            if ((*frec)[w] == 1) current_answer++;
        }
        (*vis)[u] = not (*vis)[u];
    }
    void solve() {
        vis = new vector <bool> (V + 1, false);
        frec = new vector <int> (static_cast <int> (G -> arr -> size()), 0);
        answers = new vector <int> (Q);
        sort(begin(*query), end(*query));
        int mo_left = 0, mo_right = -1;
        for (int i = 0; i < Q; i++) {
            while (mo_right < (*query)[i].right) visit(++mo_right);
            while (mo_right > (*query)[i].right) visit(mo_right--);
            while (mo_left < (*query)[i].left) visit(mo_left++);
            while (mo_left > (*query)[i].left) visit(--mo_left);
            if ((*query)[i].rollback) visit((*query)[i].lca);
            (*answers)[(*query)[i].id] = current_answer;
            if ((*query)[i].rollback) visit((*query)[i].lca);
        }
    }
    void printAnswers() {
        for (const int& ans_i : (*answers)) cout << ans_i << endl;
    }
}

void readQueries() {
    query = new vector <Query> (Q);
    for (int i = 0, u, v, L, R; i < Q; i++) {
        cin >> u >> v;
        if (G -> getStart(u) > G -> getStart(v)) swap(u, v);
        int P = G -> getLCA(u, v);
        if (P == u) L = G -> getStart(u), R = G -> getStart(v);
        else L = G -> getFinish(u), R = G -> getStart(v);
        (*query)[i] = Query(L, R, G -> getStart(P), i, P != u);
    }
}

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
}

int main() {
    G = new Tree;
    cin >> V >> Q;
    BLOCK_SIZE = sqrt(V);
    G -> readWeights();
    G -> readGraph();
    G -> build();
    readQueries();
    Solver::solve();
    Solver::printAnswers();
    delete G;
    return (0);
}
