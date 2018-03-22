#include <bits/stdc++.h>

using namespace std;

const int LEN = 25, MAX_ASCII = 100;

char name[LEN], unavailable[] = "AEIOUYWH";
int code, mp[MAX_ASCII];

bool canBeEncoded(int id) {
    for (int i = 0; i < 8; i++)
        if (name[id] == unavailable[i]) return false;
    return mp[name[id]] != mp[name[id - 1]];
}

int soundexCode() {
    code = 0;
    for (int i = 1; name[i] and code < 100; i++)
        if ( canBeEncoded(i) ) code = code * 10 + mp[name[i]];
    while (code and code < 100) code *= 10;
    return code;
}

int main() {
    mp['B'] = mp['P'] = mp['F'] = mp['V'] = 1;
    mp['C'] = mp['S'] = mp['K'] = mp['G'] = mp['J'] = mp['Q'] = mp['X'] = mp['Z'] = 2;
    mp['D'] = mp['T'] = 3;
    mp['L'] = 4;
    mp['M'] = mp['N'] = 5;
    mp['R'] = 6;
    printf("%9s%-25s%s\n", " ", "NAME", "SOUNDEX CODE");
    while (scanf("%s", name) == 1)
        printf("%9s%-25s%c%.3d\n", " ", name, name[0], soundexCode());
    printf("%19s%s\n", " ", "END OF OUTPUT");
    return(0);
}