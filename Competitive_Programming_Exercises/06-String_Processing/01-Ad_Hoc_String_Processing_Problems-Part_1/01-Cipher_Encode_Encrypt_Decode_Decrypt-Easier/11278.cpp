#include <bits/stdc++.h>

using namespace std;

const int LEN = 1010;

char line[LEN];
map <char, char> mp;

int main(){
   mp['`'] = '`', mp['1'] = '1', mp['2'] = '2', mp['3'] = '3', mp['4'] = 'q', mp['5'] = 'j', mp['6'] = 'l', mp['7'] = 'm', mp['8'] = 'f', mp['9'] = 'p', mp['0'] = '/', mp['-'] = '[', mp['='] = ']';
   mp['q'] = '4', mp['w'] = '5', mp['e'] = '6', mp['r'] = '.', mp['t'] = 'o', mp['y'] = 'r', mp['u'] = 's', mp['i'] = 'u', mp['o'] = 'y', mp['p'] = 'b', mp['['] = ';', mp[']'] = '=', mp['\\'] = '\\';
   mp['a'] = '7', mp['s'] = '8', mp['d'] = '9', mp['f'] = 'a', mp['g'] = 'e', mp['h'] = 'h', mp['j'] = 't', mp['k'] = 'd', mp['l'] = 'c', mp[';'] = 'k', mp['\''] = '-';
   mp['z'] = '0', mp['x'] = 'z', mp['c'] = 'x', mp['v'] = ',', mp['b'] = 'i', mp['n'] = 'n', mp['m'] = 'w', mp[','] = 'v', mp['.'] = 'g';
   
   mp['~'] = '~', mp['!'] = '!', mp['@'] = '@', mp['#'] = '#', mp['$'] = 'Q', mp['%'] = 'J', mp['^'] = 'L', mp['&'] = 'M', mp['*'] = 'F', mp['('] = 'P', mp[')'] = '?', mp['_'] = '{', mp['+'] = '}';
   mp['Q'] = '$', mp['W'] = '%', mp['E'] = '^', mp['R'] = '>', mp['T'] = 'O', mp['Y'] = 'R', mp['U'] = 'S', mp['I'] = 'U', mp['O'] = 'Y', mp['P'] = 'B', mp['{'] = ':', mp['}'] = '+', mp['|'] = '|';
   mp['A'] = '&', mp['S'] = '*', mp['D'] = '(', mp['F'] = 'A', mp['G'] = 'E', mp['H'] = 'H', mp['J'] = 'T', mp['K'] = 'D', mp['L'] = 'C', mp[':'] = 'K', mp['"'] = '_';
   mp['Z'] = ')', mp['X'] = 'Z', mp['C'] = 'X', mp['V'] = '<', mp['B'] = 'I', mp['N'] = 'N', mp['M'] = 'W', mp['<'] = 'V', mp['>'] = 'G', mp['?'] = '"';
   mp[' '] = ' ';

   while(cin.getline(line, LEN)){
      for(int it = 0; line[it]; it++){
         if( line[it] == '/' ) putchar('\'');
         else putchar( mp[line[it]] );
      }
      putchar('\n');
   }
   return(0);
}
