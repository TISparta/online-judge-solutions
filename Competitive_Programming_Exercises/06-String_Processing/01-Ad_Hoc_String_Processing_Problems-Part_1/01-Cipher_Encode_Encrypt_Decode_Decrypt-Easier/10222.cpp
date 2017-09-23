#include <bits/stdc++.h>

using namespace std;

string ans;
vector <string> words;
map <char, char> mp;

void precal() {
    words.push_back("1234567890-+");
    words.push_back("qwertyuiop[]");
    words.push_back("asdfghjkl:'");
    words.push_back("zxcvbnm,.");
    for(int i = 0; i < words.size(); i++)
        for(int j = 2; j < words[i].size(); j++)
            mp[ words[i][j] ] = words[i][j - 2];
    mp[' '] = ' ', mp[','] = 'n', mp['.'] = 'm';
    mp[':'] = mp[';'] = 'k';
}

int main() {
    precal();
    getline(cin, ans);
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    for(int i = 0; i < ans.size(); i++) ans[i] = mp[ ans[i] ];
    cout << ans << endl;
    return(0);
}