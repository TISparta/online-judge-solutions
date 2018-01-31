#include <bits/stdc++.h>

#define WIN   1
#define FAIL -1

using namespace std;

typedef long long ll;

ll num_1, num_2;

int minVal(ll, ll);
int maxVal(ll, ll);

int minVal(ll _max, ll _min) {
    if (_max % _min == 0) return FAIL;
    int res = WIN;
    for (ll k = (_max / _min) * _min; res != FAIL and k >= 1; k -= _min)
        res = min(res, (_max == k) ? FAIL : maxVal(max(_max - k, _min), min(_max - k, _min)));
    return res;
}


int maxVal(ll _max, ll _min) {
    if (_max % _min == 0) return WIN;
    int res = FAIL;
    for (ll k = (_max / _min) * _min; res != WIN and k >= 1; k -= _min)
        res = max(res, (_max == k) ? WIN : minVal(max(_max - k, _min), min(_max - k, _min)));
    return res;
}

int minimax(ll a, ll b) {
    return maxVal(a, b);
}

int main() {
    while (scanf("%lld %lld", &num_1, &num_2), num_1 and num_2)
        puts(minimax(max(num_1, num_2), min(num_1, num_2)) == WIN ? "Stan wins" : "Ollie wins");
    return (0);
}