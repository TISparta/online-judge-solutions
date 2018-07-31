#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100, LEN = 10;

int tc, n;
char code[SIZE][LEN];
bool ok;

bool prefix(int i, int j){
   int l1 = strlen(code[i]), l2 = strlen(code[j]);
   for(int it = 0; it < min(l1, l2); it++)
      if( code[i][it] != code[j][it] ) return false;
   return true;
}

int main(){
   while(~scanf("%s", code[0])){
      ok = true;
      n = 1;
      while( scanf("%s", code[n]), code[n][0] != '9' ) n++;
      for(int i = 0; i < n and ok ; i++)
         for(int j = i + 1; j < n and ok; j++)
            if( prefix(i, j) ) ok = false;
      printf("Set %d ", ++tc);
      puts( ok ? "is immediately decodable" : "is not immediately decodable" );
   }
   return(0);
}
