#include <bits/stdc++.h>

#define SIZE 25

using namespace std;

int n,v;
long memo[SIZE][SIZE];

long dp(int i,int j){
	if(~memo[i][j]) return memo[i][j];
	long a = 0, b = 0;
	if(i>=j){
		if(i==n) a = 0;
		else
			for(int k=i+1;k<=n;k++) a = max(a,dp(k,1)+dp(k,j));
		if(j==0) b = 0;
		else
			for(int k=1;k<j;k++) b = max(b,dp(i,k)+dp(n,k));
	}
	else
		for(int k=i;k<j;k++) a = max(a,dp(i,k)+dp(k+1,j));
	return memo[i][j] = a+b;
}

int main(){
	while(scanf("%d %d",&n,&v)==2){
		memset(memo,-1,sizeof memo);
		memo[n][1] = v;
		printf("%ld\n",dp(1,n));
	}
	return(0);
}
