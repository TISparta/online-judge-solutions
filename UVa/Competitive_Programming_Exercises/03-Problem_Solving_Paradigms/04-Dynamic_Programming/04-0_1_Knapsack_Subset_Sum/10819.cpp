#include <bits/stdc++.h>

#define MAX_N 110
#define MAX_M 11000

using namespace std;

int m,n,p[MAX_N],f[MAX_N],memo[MAX_N][MAX_M];

int dp(int it,int price){
	if(price>m){
		if(m<=1800) return -INT_MAX;
		if(price>m+200) return -INT_MAX;
	}
	if(it==n){
		if(price>m && price<=2000) return -INT_MAX;
		return 0;
	}
	if(memo[it][price]!=-1) return memo[it][price];
	return memo[it][price] = max(dp(it+1,price),f[it]+dp(it+1,price+p[it]));
}

int main(){
	while(scanf("%d %d",&m,&n)==2){
		for(int i=0;i<n;i++) scanf("%d %d",&p[i],&f[i]);
		memset(memo,-1,sizeof memo);
		printf("%d\n",dp(0,0));
	}
	return(0);
}
