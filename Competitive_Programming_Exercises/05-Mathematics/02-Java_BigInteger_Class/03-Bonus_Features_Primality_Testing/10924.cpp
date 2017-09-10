#include <bits/stdc++.h>

using namespace std;

int sum;
char word[25];
map <char, int> mp;

bool isPrime(int num){
   for(int i = 2; i * i <= num; i++)
      if( num % i == 0 ) return false;
   return true;
}

int main(){
   for(char ch = 'a', ct = 1; ch <= 'z'; ch++, ct++) mp[ch] = ct;
   for(char ch = 'A', ct = 27; ch <= 'Z'; ch++, ct++) mp[ch] = ct;
   while(~scanf("%s", word)){
      sum = 0;
      for(int i = 0; word[i]; i++) sum += mp[word[i]];
      if( isPrime(sum) ) puts("It is a prime word.");
      else puts("It is not a prime word.");
   }
   return(0);
}
