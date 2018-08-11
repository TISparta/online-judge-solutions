/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Pattern Finding, Minimax
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

namespace Pattern {
    int minVal(int);
    int maxVal(int);
}

namespace Pattern {

    const int WIN  =  1;
    const int FAIL = -1;
    vector <int> S;

    int minVal(int pile) {
        if (pile == 0) return WIN;
        int ret = WIN;
        for (int i = 0; i < S.size() and ret != FAIL and S[i] <= pile; i++)
            ret = min(ret, maxVal(pile - S[i]));
        return ret;
    }
    
    int maxVal(int pile) {
        if (pile == 0) return FAIL;
        int ret = FAIL;
        for (int i = 0; i < S.size() and ret != WIN and S[i] <= pile; i++)
            ret = max(ret, minVal(pile - S[i]));
        return ret;
    }

    inline bool isPrime(int p) {
        if (p == 1) return false;
        int n_divisors = 0;
        for (int d = 1; d <= p; d++) n_divisors += p % d == 0;
        return n_divisors == 2;
    }

    void generateS(int limit) {
        S = {1};
        for (int num = 2; num <= limit; num++)
            if (isPrime(num)) {
                for (int pib = num; pib <= limit; pib *= num)
                    S.push_back(pib);
            }
        sort(S.begin(), S.end());
    }

    void find(int limit) {
        generateS(limit);
        puts("N-positions");
        for (int N = 1; N <= limit; N++) if (maxVal(N) == FAIL) printf("%3d\n", N);
    }

}

long long T, N;

int main() {
    //Pattern::find(30);
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        puts(N % 6 == 0 ? "Misha" : "Chef");
    }
    return (0);
}
