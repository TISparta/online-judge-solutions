#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int n, from, to, k, pos_from, pos_to;
char word1[SIZE], word2[SIZE], s[SIZE];
vector < vector <int> > v(SIZE);

int find(int num){
   for(int i = 0; i < n; i++)
      for(int j = 0; j < v[i].size(); j++)
         if(v[i][j] == num) return i;
}

void returning(int pos, int num){
   for(int i = v[pos].size() - 1; i >= 0; i--)
      if(v[pos].back() == num) break;
      else v[v[pos].back()].push_back(v[pos].back()), v[pos].pop_back();
}

void moves(int source, int num, int target){
   vector <int> aux;
   for(int i = v[source].size() - 1; i >= 0; i--)
      if(v[source].back() == num){
         aux.push_back(v[source].back());
         v[source].pop_back();
         break;
      }
      else aux.push_back(v[source].back()), v[source].pop_back();
   reverse(aux.begin(), aux.end());
   v[target].insert(v[target].end(), aux.begin(), aux.end());
}

int main(){
   scanf("%d\n",&n);
   for(int i = 0;i < n; i++) v[i].push_back(i);
   while(true){
      cin.getline(s, SIZE);
      k = sscanf(s,"%s %d %s %d", word1, &from, word2, &to);
      if(k == 1) break;
      if(strcmp(word1, "move") == 0){
         if(strcmp(word2, "onto") == 0){
            pos_from = find(from);
            pos_to = find(to);
            if(pos_from == pos_to) continue;
            returning(pos_from, from);
            returning(pos_to, to);
            v[pos_to].push_back(v[pos_from].back());
            v[pos_from].pop_back();
         }
         else{
            pos_from = find(from);
            pos_to = find(to);
            if(pos_from == pos_to) continue;
            returning(pos_from,from);
            v[pos_to].push_back(v[pos_from].back());
            v[pos_from].pop_back();
         }
      }
      else{
         if(strcmp(word2, "onto") == 0){
            pos_from = find(from);
            pos_to = find(to);
            returning(pos_to, to);
            moves(pos_from, from, pos_to);
         }
         else{
            pos_from = find(from);
            pos_to = find(to);
            moves(pos_from, from, pos_to);
         }
      }
   }
   for(int i = 0; i < n; i++){
      printf("%d:", i);
      for(int j = 0; j < v[i].size(); j++)
         printf(" %d", v[i][j]);
      puts("");
   }  
   return(0);
}
