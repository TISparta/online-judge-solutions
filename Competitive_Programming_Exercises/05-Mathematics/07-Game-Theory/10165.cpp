#include <bits/stdc++.h>

using namespace std;

int n, num, sum;

int main() {
    while (scanf("%d", &n), n) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            sum ^= num;
        }
        puts(sum == 0 ? "No" : "Yes");
    }
    return (0);
}