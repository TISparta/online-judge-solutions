#include <bits/stdc++.h>

using namespace std;

int tc, m[50], p, ans;
char s[10][10];
vector <int> G[50];
int x[] = {-2,-2,2,2,-1,-1,1,1};
int y[] = {-1,1,-1,1,-2,2,-2,2};
int solution[] = {1,1,1,1,1,
                  0,1,1,1,1,
                  0,0,-1,1,1,
                  0,0,0,0,1,
                  0,0,0,0,0};
int target = 12;

bool isSolved(){
   for(int i = 0; i < 25; i++)
      if(solution[i] != m[i]) return false;
   return true;
}

void xor_swap(int *a, int *b){
   *a ^= *b, *b ^= *a, *a ^= *b;
}

void backtrack(int source,int steps){
   if(steps == 11) return;
   if(source == target && isSolved()){
      ans = min(ans, steps);
      return;
   }
   for(int i = 0; i < G[source].size(); i++){
      xor_swap(&m[source], &m[G[source][i]]);
      backtrack(G[source][i], steps + 1);
      xor_swap(&m[source], &m[G[source][i]]);
   }
}

inline bool isValid(int row, int column){
   return (row >= 0 && column >= 0 && row < 5 && column < 5);
}

void initGraph(){
   for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
         for(int k = 0; k < 8; k++){
            int p = i + x[k], q = j + y[k];
            if(isValid(p, q)){
               int pp = i * 5 + j, qq = p * 5 + q;
               G[pp].push_back(qq);
            }
         }
}

void initMatrix(){
   for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
         if(s[i][j] == '1') m[i * 5 + j] = 1;
         else if(s[i][j] == '0') m[i * 5 + j] = 0;
         else if(s[i][j] == ' ') m[i * 5 + j] = -1, p = i * 5 + j;
}

int main(){
   initGraph();
   scanf("%d\n", &tc);
   while(tc--){
      ans = 12;
      for(int i = 0; i < 5; i++) cin.getline(s[i], 10);
      initMatrix();
      backtrack(p, 0);
      if(ans == 12) printf("Unsolvable in less than 11 move(s).\n");
      else printf("Solvable in %d move(s).\n", ans);
   }
   return(0);
}
