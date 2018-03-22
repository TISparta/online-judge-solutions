#include <bits/stdc++.h>

using namespace std;

const int SIZE = 7;

int tc, sum, arr[SIZE], ac[SIZE];
bool can;
vector < vector <int> > ways[SIZE];

void print() {
    printf("Collection #%d:\n", ++tc);
    puts(can ? "Can be divided.\n" : "Can't be divided.\n");
}

bool complete() {
    bool ok = true;
    for (int i = 1; i <= 6; i++) ok &= (arr[i] == 0);
    return ok;
}

bool isValid(int id, int j, int ct) {
    for (int i = 1; i <= 6; i++)
        if (arr[i] < ct * ways[id][j][i]) return false;
    return true;
}

void sub(int id, int j, int ct) {
    for (int i = 1; i <= 6; i++)
        arr[i] -= ct * ways[id][j][i];
}

void add(int id, int j, int ct) {
    for (int i = 1; i <= 6; i++)
        arr[i] += ct * ways[id][j][i];
}

void backtrack(int id = 6) {
    if (can) return;
    if (id == 0) {
        can |= complete();
        return;
    }
    backtrack(id - 1);
    for (int ct = 1; ct <= arr[id]; ct++) {
        arr[id] -= ct;
        for (int j = 0; j < ways[id].size(); j++)
            if (isValid(id, j, ct)) {
                sub(id, j, ct);
                backtrack(id - 1);
                add(id, j, ct);
            }
        arr[id] += ct;
    }
}

void init() {
    can = false;
}

void solve() {
    init();
    backtrack();
}

bool read() {
    sum = 0;
    for (int i = 1; i <= 6; i++) scanf("%d", arr + i), sum += arr[i];
    return sum;
}

void precal() {
    for (int x1 = 0; x1 <= 6 / 1; x1++)
        for (int x2 = x1; x2 <= 6 / 2; x2++)
            for (int x3 = x2; x3 <= 6 / 3; x3++)
                for (int x4 = x3; x4 <= 6 / 4; x4++)
                    for (int x5 = x4; x5 <= 6 / 5; x5++)
                        for (int x6 = x5; x6 <= 6 / 6; x6++) {
                            int s = x1 * 1 + x2 * 2 + x3 * 3 + x4 * 4 + x5 * 5 + x6 * 6;
                            if (1 <= s and s <= 6)
                                ways[s].push_back({0, x1, x2, x3, x4, x5, x6});
                        }
    for (int i = 1; i <= 6; i++) cout << ways[i].size() << endl;
}

int main() {
    precal();
    /*while (read()) {
        solve();
        print();
    }*/
    return (0);
}