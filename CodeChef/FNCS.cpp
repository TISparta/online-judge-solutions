/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tags : Sqrt decomposition, BIT
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ll;
 
const int MAX_N = 1e5, OFFSET = 10;
 
template <typename T>
struct BIT {
    int M;
    vector <T> ft;
    BIT() {}
    void build(int M_)  {
        M = M_;
        ft.resize(M_, 0);
    }
    void update(int pos, const T& val) {
        while (pos < M) {
            ft[pos] += val;
            pos += pos bitand -pos;
        }
    }
    T get(int pos) {
        T sum = 0;
        while (pos) {
            sum += ft[pos];
            pos = pos bitand (pos - 1);
        }
        return sum;
    }
 
};
 
struct Chunk {
    int M;
    BIT <int> frec;
    ll sum;
    Chunk (int M_): M(M_) {
        frec.build(M_);
        sum = 0;
    }
};
 
int N, Q, BLOCK_SIZE, LL[MAX_N + OFFSET], RR[MAX_N + OFFSET], arr[MAX_N + OFFSET]; 
BIT <ll> ac;
vector <Chunk> chunks;
 
ll getSum(int L, int R) {
    ll sum = 0;
    while (L <= R and L % BLOCK_SIZE != 0) {
        sum += ac.get(RR[L]) - ac.get(LL[L] - 1);
        L++;
    }
    while (L + BLOCK_SIZE <= R and L % BLOCK_SIZE == 0) {
        sum += chunks[L / BLOCK_SIZE].sum;
        L += BLOCK_SIZE;    
    }
    while (L <= R) {
        sum += ac.get(RR[L]) - ac.get(LL[L] - 1);
        L++;
    }
    return sum;
}
 
void changeElement(int x, int y) {
    for (int i = 0; i < chunks.size(); i++) {
        int ct = chunks[i].frec.get(x);
        chunks[i].sum = chunks[i].sum - 1LL * ct * arr[x] + 1LL * ct * y;
    }
    ac.update(x, y - arr[x]);
    arr[x] = y;
}
 
void processQuery() {
    int type, L, R;
    scanf("%d %d %d", &type, &L, &R);
    if (type == 1) {
        changeElement(L, R);
    }
    else {
        printf("%llu\n", getSum(L, R));
    }
}
 
void readInput() {
    scanf("%d", &N);
    ac.build(N + OFFSET);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        ac.update(i, arr[i]);
    }
    BLOCK_SIZE = sqrt(N);
    for (int i = 0; i <= N / BLOCK_SIZE + 1; i++)
        chunks.push_back(Chunk(N + OFFSET));
    chunks.push_back(Chunk(N + OFFSET));
    for (int i = 1, id, L, R; i <= N; i++) {
        scanf("%d %d", &LL[i], &RR[i]);
        id = i / BLOCK_SIZE;
        chunks[id].frec.update(LL[i], 1);
        chunks[id].frec.update(RR[i] + 1, -1);
        chunks[id].sum += ac.get(RR[i]) - ac.get(LL[i] - 1);
    }
}
 
int main() {
    readInput();
    scanf("%d", &Q);
    while (Q--) processQuery();
}
