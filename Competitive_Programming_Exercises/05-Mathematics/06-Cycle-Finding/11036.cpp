#include <bits/stdc++.h>

using namespace std;

const int SIZE = 110, LEN = 110;

int N, n, m;
long long a, b;
char line[LEN], *p_, v[SIZE][9];

int f(long long x){
   stack <long long> st;
   for(int i = 0; i < m; i++){
      if( v[i][0] == 'x' ) st.push(x % N);
      else if( v[i][0] == 'N' ) st.push(N);
      else if( isdigit(v[i][0]) ) st.push(atoll(v[i]) % N);
      else{
         a = st.top(), st.pop();
         b = st.top(), st.pop();
         if( v[i][0] == '+' ) st.push( ( a + b ) % N);
         else if( v[i][0] == '*' ) st.push( ( a * b ) % N);
         else return b % N;
      }
   }
}

int Brent_Cycle_Finding(long long xo){
   long long p = 1, lambda = 1, tortoise = f(xo), hare = f(f(xo));
   while( tortoise != hare ){
      if( p == lambda ) tortoise = hare, p <<= 1, lambda = 0;
      hare = f(hare);
      lambda++;
   }
   return lambda;
}

int main(){
   while(scanf("%d %d ", &N, &n), N | n){
      cin.getline(line, LEN);
      p_ = strtok(line, " "), m = 0;
      while(p_) strcpy(v[m++], p_), p_ = strtok(NULL, " ");
      printf("%d\n", Brent_Cycle_Finding(n));
   }
   return(0);
}
