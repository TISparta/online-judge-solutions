#include <bits/stdc++.h>

#define SIZE 10010

using namespace std;

int tc,L,S,memo[30][SIZE][30];

int dp(int ct,int sum,char ch){
	if(ct==0 && sum==0) return 1;
	if(!('a'<=ch && ch<='z') || sum<0 || ct<0 || ct>26 || sum>351) return 0;
	if(~memo[ct][sum][ch-'a']) return memo[ct][sum][ch-'a'];
	return memo[ct][sum][ch-'a'] = dp(ct-1,sum-(ch-'a'+1),ch+1)+dp(ct,sum,ch+1);
}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&L,&S),L|S)
		printf("Case %d: %d\n",++tc,dp(L,S,'a'));
	return(0);
}
