#include <bits/stdc++.h>

#define SIZE 10

using namespace std;

int n, die[SIZE], tmp;
char command[SIZE];

void move1(){
   tmp = die[1];
   die[1] = die[5], die[5] = die[6], die[6] = die[2];
   die[2] = tmp;
}

void move2(){
   tmp = die[1];
   die[1] = die[2], die[2] = die[6], die[6] = die[5];
   die[5] = tmp;
}

void move3(){
   tmp = die[1];
   die[1] = die[3], die[3] = die[6], die[6] = die[4];
   die[4] = tmp;
}

void move4(){
   tmp = die[1];
   die[1] = die[4], die[4] = die[6], die[6] = die[3];
   die[3] = tmp;
}

int main(){
   while(scanf("%d\n", &n), n){
      for(int it = 1; it <= 6; it++) die[it] = it;
      while(n--){
         scanf("%s", command);
         if( command[0] == 'n' ) move1();
         else if( command[0] == 's' ) move2();
         else if( command[0] == 'e' ) move3();
         else move4();
      }
      printf("%d\n", die[1]);
   }
   return(0);
}
