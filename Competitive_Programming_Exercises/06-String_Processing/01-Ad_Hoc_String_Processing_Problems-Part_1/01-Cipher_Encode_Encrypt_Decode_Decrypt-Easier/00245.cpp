#include <bits/stdc++.h>

using namespace std;

int id;
string line, word, tmp;
deque <string> words;

void putWord(int id) {
    tmp = words[id];
    printf("%s", tmp.c_str());
    words.erase(words.begin() + id);
    words.push_front(tmp);
}

void uncompress() {
    word = "";
    for (int i = 0; i < line.size(); i++)
        if ( isdigit(line[i]) ) {
            id = line[i] - '0';
            while (i + 1 < line.size() and isdigit(line[i + 1])) id = id * 10 + (line[++i] - '0');
            putWord(--id);
            word = "";
        }
        else if ( isalpha(line[i]) ) word += line[i];
        else {
            printf("%s", word.c_str());
            putchar(line[i]);
            if (not word.empty()) words.push_front(word);
            word = "";
        }
    if (not word.empty()) {
        printf("%s", word.c_str());
        words.push_front(word);
    }
    putchar('\n');
}

int main() {
    while (getline(cin, line), line[0] != '0') uncompress();
    return(0);
}