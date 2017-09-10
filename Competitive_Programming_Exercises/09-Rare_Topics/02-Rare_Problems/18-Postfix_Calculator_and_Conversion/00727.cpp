#include <bits/stdc++.h>

using namespace std;

int tc;
char ch, ch1;
map < char, int > priority;

int main(){
   priority['+'] = priority['-'] = 1;
   priority['*'] = priority['/'] = 2;
   scanf("%d\n", &tc);
   while(tc--){
      stack <char> st;
      while(scanf("%c", &ch) == 1){
         if( ch == '\n' ) break;
         getchar();
         if( isdigit(ch) ) putchar(ch);
         else if( ch == ')' ){
            while( not st.empty() ){
               ch = st.top();
               st.pop();
               if( ch == '(' ) break;
               putchar(ch);
            }
         }
         else if( ch == '(' )
            st.push(ch);
         else{
            if( not st.empty() and priority[st.top()] >= priority[ch] )
               while( not st.empty() ){
                  ch1 = st.top();
                  if( ch1 == '(' or priority[ch1] < priority[ch] ) break;
                  st.pop();
                  putchar(ch1);
               }
            st.push(ch);
         }
      }
      while( not st.empty() ) putchar(st.top()), st.pop();
      putchar('\n');
      if( tc ) putchar('\n');
   }
   return(0);
}
