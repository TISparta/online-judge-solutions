#include <bits/stdc++.h>

using namespace std;

const int SIZE = 110, LEN = 100;

struct Pilot{
   char name[LEN], s[LEN];
   int min, sec, ms;
   Pilot() {};
   void to_lower(){
      strcpy(s, name);
      for(int it = 0; s[it]; it++)
         s[it] = tolower(s[it]);
   }
   bool operator < (Pilot& other){
      if( min != other.min ) return min < other.min;
      if( sec != other.sec ) return sec < other.sec;
      if( ms != other.ms ) return ms < other.ms;
      return strcmp(s, other.s) < 0;
   }
};

int n;
char line[LEN];
Pilot v[SIZE];

int main(){
   while(~scanf("%d\n", &n)){
      for(int it = 0; it < n; it++){
         cin.getline(line, LEN);
         sscanf(line, "%s : %d min %d sec %d ms", v[it].name, &v[it].min, &v[it].sec, &v[it].ms);
         v[it].to_lower();
      }
      sort(v, v + n);
      for(int it = 0; it < n; it++){
         if( it % 2 == 0 ) printf("Row %d\n", it / 2 + 1);
         printf("%s\n", v[it].name);
      }
      putchar('\n');
   }
   return(0);
}
