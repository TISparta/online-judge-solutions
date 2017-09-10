#include <bits/stdc++.h>

#define LIM 46

using namespace std;

int n;
vector <long> seq;

int main(){
   seq.push_back(0), seq.push_back(1), seq.push_back(2);
   for(int i = 3; i < LIM; i++)
      seq.push_back(seq[i - 1]+seq[i - 2] + 1);
   while(scanf("%d", &n), n != -1)
      printf("%ld %ld\n", seq[n], seq[n + 1]);
   return(0);
}
