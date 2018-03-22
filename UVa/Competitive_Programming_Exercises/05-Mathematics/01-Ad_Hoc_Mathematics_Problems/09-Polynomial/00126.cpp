#include <bits/stdc++.h>

using namespace std;

const int LEN = 100;

struct Term{
   int c, ex, ey;
   Term(int c_, int ex_, int ey_) : c(c_), ex(ex_), ey(ey_) {};
   bool operator < (const Term& other){
      if( ex != other.ex ) return ex > other.ex;
      return ey < other.ey;
   }
   bool operator == (const Term& other){
      return ( ex == other.ex and ey == other.ey );
   }
   Term operator * (const Term& other){
      return Term(c * other.c, ex + other.ex, ey + other.ey);
   }
};

char s[LEN], ch1, ch2, output[3][LEN];
int coef, e1, e2, it, len, len1, len2;
vector < Term > p, p1, p2;
string x;

void reading(vector < Term > &p){
   p.clear(), x = "";
   it = ( s[0] == '-' or s[0] == '+' ) ? 1 : 0;
   if( s[0] == '-' ) x += "-";
   else x += "+";
   while(s[it]){
      if( s[it] == '-' or s[it] == '+' ) break;
      if( x.back() == 'x' and s[it] == 'y' ) x += "1";
      if( x.back() == 'y' and s[it] == 'x' ) x += "1";
      x += s[it++];
   }
   if( not isdigit(x[1]) ) x.insert(1, "1");
   if( not isdigit(x.back()) ) x += "1";
   if( x.find('y') == string::npos ) x += "y0";
   if( x.find('x') == string::npos ) x += "x0";
   sscanf(x.c_str(), "%d%c%d%c%d", &coef, &ch1, &e1, &ch2, &e2);
   if( ch1 == 'x' )
      p.push_back( Term(coef, e1, e2) );
   else
      p.push_back( Term(coef, e2, e1) );
   while(s[it]){
      x.clear();
      x += s[it++];
      while(s[it]){
         if( s[it] == '-' or s[it] == '+' ) break;
         if( x.back() == 'x' and s[it] == 'y' ) x += "1";
         if( x.back() == 'y' and s[it] == 'x' ) x += "1";
         x += s[it++];
      }
      if( not isdigit(x[1]) ) x.insert(1, "1");
      if( not isdigit(x.back()) ) x += "1";
      if( x.find('y') == string::npos ) x += "y0";
      if( x.find('x') == string::npos ) x += "x0";
      for(int k = 1; k < x.size(); k++)
         if( ( x[k] == 'x' and x[k - 1] == 'y' ) or ( x[k] == 'y' and x[k - 1] == 'x' ) )
            x.insert(k, "1");
      sscanf(x.c_str(), "%d%c%d%c%d", &coef, &ch1, &e1, &ch2, &e2);
      if( ch1 == 'x' )
         p.push_back( Term(coef, e1, e2) );
      else
         p.push_back( Term(coef, e2, e1) );
   }
}

void print(vector <Term> &p){
   memset(output, ' ', sizeof output);
   it = 0;
   for(int i = 0; i < p.size(); i++){
      if( p[i].c < 0 ) output[1][it++] = '-';
      if( i and p[i].c > 0 ) output[1][it++] = '+';
      if( i ) it++;
      if( abs(p[i].c) != 1 or ( abs(p[i].c) == 1 and p[i].ex == 0 and p[i].ey == 0) ){
         x = to_string(p[i].c);
         if( x[0] == '-' ) x.erase(x.begin());
         for(int k = 0; k < x.size(); k++)
            output[1][it++] = x[k];
      }
      if( p[i].ex ){
         output[1][it++] = 'x';
         if( p[i].ex > 1 ){
            x = to_string(p[i].ex);
            for(int k = 0; k < x.size(); k++)
               output[0][it++] = x[k];
         }
      }
      if( p[i].ey ){
         output[1][it++] = 'y';
         if( p[i].ey > 1 ){
            x = to_string(p[i].ey);
            for(int k = 0; k < x.size(); k++)
               output[0][it++] = x[k];
         }
      }
      it++;
   }
   if( output[1][0] == ' ' ) output[1][0] = '0';
   len = 2;
   for(int i = LEN - 1; i >= 0 and output[0][i] == ' '; i--) len1 = i;
   for(int i = LEN - 1; i >= 0 and output[1][i] == ' '; i--) len2 = i;
   len = max(len1, len2);
   output[0][len] = output[1][len] = '\0';
   if( len1 == 0 and output[1][0] == '0' ) output[0][0] = '\0';
   printf("%s\n", output[0]);
   printf("%s\n", output[1]);
}

int main(){
   while(scanf("%s", s)){
      if( s[0] == '#' ) break;
      reading(p1);
      scanf("%s", s);
      reading(p2);
      p.clear();
      for(int i = 0; i < p1.size(); i++)
         for(int j = 0; j < p2.size(); j++){
            Term ret = p1[i] * p2[j];
            bool found = false;
            for(int k = 0; k < p.size() and not found; k++)
               if( p[k] == ret ) p[k].c += ret.c, found = true;
            if( not found ) p.push_back(ret);
         }
      sort(p.begin(), p.end());
      for(int it = 0; it < p.size(); it++)
         if( p[it].c == 0 ) p.erase(p.begin() + it), it--;
      print(p);
   }
   return(0);
}
