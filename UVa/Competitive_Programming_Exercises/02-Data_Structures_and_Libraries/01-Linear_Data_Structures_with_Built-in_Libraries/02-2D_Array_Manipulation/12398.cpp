#include <bits/stdc++.h>

#define SIZE 210

using namespace std;

char s[SIZE];
int tc, v[5][5], x, y;
int dx[] = {-1, 0, 0, 1, 0};
int dy[] = {0, 1, -1, 0, 0};

void inc(int pos){
   x = pos / 3 + 1, y = pos % 3 + 1;
   for(int it = 0; it < 5; it++)
      v[x + dx[it]][y + dy[it]] = (v[x + dx[it]][y + dy[it]] + 1) % 10;
}

void printMatrix(){
   printf("Case #%d:\n", ++tc);
   for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++)
         printf( j != 3 ? "%d " : "%d\n", v[i][j]);
}

int main(){
   while(cin.getline(s, SIZE)){
      memset(v, 0, sizeof v);
      for(int i = 0, j = strlen(s); i < j; i++) inc(s[i] - 'a');
      printMatrix();
   }
   return(0);
}
