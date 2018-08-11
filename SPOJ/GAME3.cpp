/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Pattern Finding, Minimax
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

namespace Pattern {
    int minVal(int, int);
    int maxVal(int, int);
    string bin(long long);
    void find(int);
}

namespace Pattern {

    const int WIN  =  1;
    const int FAIL = -1;

    int minVal(int M, int N) {
        if (N == M) return FAIL;
        int ret = WIN;
        ret = min(ret, maxVal(M + 1, N));
        if (2 * M <= N) ret = min(ret, maxVal(2 * M, N));
        return ret;
    }

    int maxVal(int M, int N) {
        if (N == M) return WIN;
        int ret = FAIL;
        ret = max(ret, minVal(M + 1, N));
        if (2 * M <= N) ret = max(ret, minVal(2 * M, N));
        return ret;
    }

    string bin(long long num) {
        if (num == 0) return "0";
        string ret = "";
        while (num) ret += (num % 2) + '0', num >>= 1;
        return string(ret.rbegin(), ret.rend());
    }

    void find(int limit) {
        for (int N = 1; N <= limit; N++)
            if (maxVal(1, N) == WIN) printf("%3d %10s\n", N, bin(N).c_str());
    }

}

int T;
long long N;

bool isNposition() {
    string bin = Pattern::bin(N);
    reverse(bin.begin(), bin.end());
    if (bin[0] != '1') return false;
    for (int k = 2; k < bin.size(); k += 2) if (bin[k] == '1') return false;
    return true;
}

int main() {
    //Pattern::find(200);
    scanf ("%d", &T);
    while (T--) {
        scanf ("%lld", &N);
        puts(isNposition() ? "Ivica" : "Marica");
    }
    return (0);
}
