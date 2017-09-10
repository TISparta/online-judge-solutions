#include <bits/stdc++.h>

using namespace std;

const int SIZE = 40005;

int R, C, idx;
char ch, s[SIZE], line[SIZE], ans[SIZE];

bool is_uniform(int r, int c, int idr, int idc){
   char ch_ = line[idr * C + idc];
   for(int row = idr; row < idr + r; row++)
      for(int col = idc; col < idc + c; col++)
         if( line[row * C + col] != ch_ ) return false;
   return true;
}

void printQuarter(int r, int c, int idr, int idc){
   char ch_ = line[idx];
   for(int row = idr; row < idr + r; row++)
      for(int col = idc; col < idc + c; col++)
         ans[row * C + col] = ch_;
}

void B_to_D(int r, int c, int idr, int idc){
   if( r == 0 or c == 0 ) return;
   if( is_uniform(r, c, idr, idc) ){
      ans[++idx] = line[idr * C + idc];
      return;
   }
   ans[++idx] = 'D';
   B_to_D( (r + 1) / 2, (c + 1) / 2, idr, idc);
   B_to_D( (r + 1) / 2, c / 2, idr, idc + (c + 1)/ 2);
   B_to_D( r / 2, (c + 1) / 2, idr + (r + 1) / 2, idc);
   B_to_D( r / 2, c / 2, idr + (r + 1) / 2, idc + (c + 1)/ 2);
}

void D_to_B(int r, int c, int idr, int idc){
   if( idx >= R * C ) return;
   if( r == 0 or c == 0 ) return;
   if( line[++idx] != 'D'){
      printQuarter(r, c, idr, idc);
      return;
   }
   D_to_B( (r + 1) / 2, (c + 1) / 2, idr, idc);
   D_to_B( (r + 1) / 2, c / 2, idr, idc + (c + 1)/ 2);
   D_to_B( r / 2, (c + 1) / 2, idr + (r + 1) / 2, idc);
   D_to_B( r / 2, c / 2, idr + (r + 1) / 2, idc + (c + 1)/ 2);
}

void printAnswer(){
   int it;
   for(it = 0; ans[it]; it++){
      if( it % 50 == 0 and it ) putchar('\n');
      putchar(ans[it]);
   }
   it--;
   if( it % 50 != 0 or it == 0 )
      putchar('\n');
}

int main(){
   cin.getline(s, SIZE);
   sscanf(s, "%c %d %d", &ch, &R, &C);
   while(true){
      line[0] = '\0';
      while(cin.getline(s, SIZE)){
         if( s[0] == 'B' or ( s[0] == 'D' and s[1] == ' ' ) ) break;
         strcat(line, s);
      }
      if( ch == 'B' ){
         idx = -1;
         printf("D%4d%4d\n", R, C);
         B_to_D(R, C, 0, 0);
         ans[++idx] = '\0';
         printAnswer();
      }
      else{
         printf("B%4d%4d\n", R, C);
         idx = -1;
         D_to_B(R, C, 0, 0);
         ans[R * C] = '\0';
         printAnswer();
      }
      if( sscanf(s, "%c %d %d", &ch, &R, &C) != 3 ) break;
   }
   return(0);
}
