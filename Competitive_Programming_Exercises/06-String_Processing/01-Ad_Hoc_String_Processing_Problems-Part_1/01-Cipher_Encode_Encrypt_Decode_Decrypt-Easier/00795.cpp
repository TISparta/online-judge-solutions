#include <bits/stdc++.h>

using namespace std;

const int SIZE = 6;

int x, y;
char grid[SIZE][SIZE];
string line, _line, ans;
vector < pair <int, int> > pos = { {0, 1}, {0, 3}, {0, 5},
                                   {1, 4},
                                   {2, 2},
                                   {3, 1}, {3, 4},
                                   {4, 5},
                                   {5, 3} };

void rotate() {
    for (int i = 0; i < 9; i++) {
        x = pos[i].first, y = pos[i].second;
        pos[i].first = y, pos[i].second = 5 - x;
    }
}

void process() {
    int pib = 0;
    ans = "";
    while (pib < line.size()) {
        _line = "";
        for (int i = 0; i < 36; i++) 
            grid[i / 6][i % 6] = line[pib + i];
        for (int r = 0; r < 4; r++) {
            for(int j = 0; j < 9; j++)
                _line += grid[pos[j].first][pos[j].second];
            rotate();
            sort(pos.begin(), pos.end());
        }
        reverse(_line.begin(), _line.end());
        ans.insert(ans.begin(), _line.begin(), _line.end());
        pib += 36;
    }
    while (ans.back() == '#') ans.pop_back();
    printf("%s\n", ans.c_str());
}

int main() {
    while (getline(cin, line)) process();
    return(0);
}