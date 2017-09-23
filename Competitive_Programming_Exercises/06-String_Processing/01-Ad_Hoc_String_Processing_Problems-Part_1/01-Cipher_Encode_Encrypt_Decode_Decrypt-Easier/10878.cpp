#include <bits/stdc++.h>

using namespace std;

const int LEN = 50;

char line[LEN];
string ans;
int decNumber;
vector <int> idx = {9, 8, 7, 5, 4, 3, 2, 1};

int getDecimal() {
    int power = 1, ret = 0;
    for (int i = 0; i < idx.size(); i++) {
        if (line[ idx[i] ] == 'o') ret += power;
        power <<= 1;
    }
    return ret;
}

int main() {
    cin.getline(line, LEN);
    while (true) {
        cin.getline(line, LEN);
        decNumber = getDecimal();
        if (decNumber == 0) break;
        ans.push_back( (char) decNumber );
    }
    printf("%s", ans.c_str());
    return(0);
}