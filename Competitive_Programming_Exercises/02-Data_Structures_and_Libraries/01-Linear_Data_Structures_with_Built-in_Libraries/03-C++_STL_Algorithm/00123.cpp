#include <bits/stdc++.h>

#define MAX_WORD 60
#define MAX_TITLE 210
#define SIZE 10010

using namespace std;

struct KWIC{
   char key[SIZE], line[SIZE];
   int idx_n, idx_m;
}aux;

int n, m, it;
char word[MAX_WORD][SIZE], titles[MAX_TITLE][SIZE], s[SIZE], part[SIZE][SIZE], *p;
vector <KWIC> v;

void toLower(){
   for(int i = 0; i < m; i++)
      for(int j = 0; titles[i][j]; j++) titles[i][j] = tolower(titles[i][j]);
}

void cpy(char* x, char* y){
   int pos;
   for(pos = 0; y[pos]; pos++) x[pos] = tolower(y[pos]);
   x[pos] = '\0';
}

bool isNotIgnored(char* x){
   for(int i = 0; i < n; i++) if(strcmp(word[i], x) == 0) return false;
   return true;
}

void toUpper_nth_word(int k){
   int pos = 0;
   for(int i = 0; s[i]; i++){
      if(s[i] != ' '){
         pos++;
         if(pos == k){
            while(s[i] && s[i] != ' ') s[i] = toupper(s[i]), i++;
            break;
         }
         while(s[i] && s[i] != ' ') i++;
      }
   }
}

bool cmp(KWIC x, KWIC y){
   if(strcmp(x.key, y.key)!=0) return (strcmp(x.key, y.key) < 0);
   if(x.idx_m != y.idx_m) return (x.idx_m < y.idx_m);
   return (x.idx_n < y.idx_n);
}

int main(){
   while(scanf("%s", word[n]), strcmp(word[n], "::") != 0) n++;
   while(cin.getline(titles[m], SIZE)) m++;
   toLower();
   for(int i = 0; i < m; i++){
      strcpy(s, titles[i]);
      p = strtok(s, " "), it = 0;
      while(p) cpy(part[it++], p), p = strtok(NULL, " ");
      for(int j = 0; j < it; j++)
         if(isNotIgnored(part[j])){
            strcpy(s, titles[i]);
            toUpper_nth_word(j + 1);
            strcpy(aux.key, part[j]);
            strcpy(aux.line, s);
            aux.idx_n = j;
            aux.idx_m = i;
            v.push_back(aux);
         }
   }
   sort(v.begin(), v.end(), cmp);
   for(int i = 0; i < v.size(); i++)
      printf("%s\n", v[i].line);
   return(0);
}
