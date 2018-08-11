/**
 * > Author : TISparta
 * > Date : 08-08-18
 * > Tags : BIT
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 200000 + 10, LOG2 = 17;

int Q, L, x;
char S;
vector <int> ft(MAX_VAL);
unordered_map <int, int> mp, inv_mp;
vector <int> arr, tmp;
vector <pair <int, int>> command;

namespace BIT {
    
    void update(int pos, const int& val) {
        while (pos < MAX_VAL) {
            ft[pos] += val;
            pos += pos bitand -pos;
        }
    }

    int get(int pos) {
        int sum = 0;
        while (pos) {
            sum += ft[pos];
            pos = pos bitand (pos - 1);
        }
        return sum;
    }

    bool has(int val) {
        return (get(val) - get(val - 1)) == 1;
    }

    int kth(int k) {
        int lift = 1 << LOG2, ans = MAX_VAL - 1;
        while (lift) {
            if (ans > lift and get(ans - lift) >= k) ans -= lift;
            lift >>= 1;
        }
        return ans;
    }

}

void readInput() {
    map <char, int> idx;
    idx['I'] = 1;
    idx['D'] = 2;
    idx['K'] = 3;
    idx['C'] = 4;
    scanf("%d\n", &Q);
    while (Q--) {
        scanf("%c %d\n", &S, &x);
        command.push_back({idx[S], x});
        if (S != 'K') arr.push_back(x);
    }
}

void compress() {
    int sigma = 0;
    tmp = arr;
    sort(begin(tmp), end(tmp));
    if (tmp.empty()) return;
    mp[tmp[0]] = ++sigma;
    inv_mp[sigma] = tmp[0];
    for (int i = 1; i < tmp.size(); i++)
        if (tmp[i - 1] != tmp[i]) {
            mp[tmp[i]] = ++sigma;
            inv_mp[sigma] = tmp[i];
        }
    for (int i = 0; i < command.size(); i++)
        if (command[i].first != 3)
            command[i].second = mp[command[i].second];
}

int main() {
    readInput();
    compress();
    for (int i = 0; i < command.size(); i++) {
        int s = command[i].first;
        x = command[i].second;
        if (s == 1) {
            if (not BIT::has(x)) L++, BIT::update(x, 1);
        }
        else if (s == 2) {
            if (BIT::has(x)) L--, BIT::update(x, -1);
        }
        else if (s == 3) {
            if (x > L) puts("invalid");
            else printf("%d\n", inv_mp[BIT::kth(x)]);
        }
        else if (s == 4) {
            printf("%d\n", BIT::get(x - 1));
        }
    }
    return (0);
}
