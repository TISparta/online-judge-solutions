#include <bits/stdc++.h>

const int EPS = 1e-9;

using namespace std;

int N, M;
vector <double> arr_1, arr_2;

double solve () {
    double theta = 0.0;
    for (double alfa_1: arr_1) {
        double min_ = 360.0;
        for (double alfa_2: arr_2) {
            min_ = min(min_, fabs(alfa_2 - alfa_1));
        }
        theta += min_;
    }
    return theta * 10000.0 / 360.0;
}

void build (int n, vector <double>& arr) {
    arr.reserve(n);
    double angle = 360.0 / n;
    arr.emplace_back(0.0);
    for (int i = 1; i < n; i++) {
        arr.emplace_back(arr.back() + angle);
    }
}

inline void clear () {
    arr_1.clear();
    arr_2.clear();
}

int main () {
    while (~scanf("%d %d", &N, &M)) {
        clear();
        build(N, arr_1);
        build(N + M, arr_2);
        printf("%.6lf\n", solve());
    }
    return (0);
}
