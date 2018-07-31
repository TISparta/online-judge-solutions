#include <bits/stdc++.h>

#define MAX_N 20
#define MAX_W 300010

using namespace std;

float n;
int v[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long memo[MAX_N][MAX_W];

long long ways(int id,int sum){
	if(sum==0) return 1;
	if(id==11 || sum<0) return 0;
	if(~memo[id][sum]) return memo[id][sum];
	return memo[id][sum] = ways(id+1,sum)+ways(id,sum-v[id]);
}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%f",&n),n!=0.00)
		printf("%6.2f%17lld\n",n,ways(0,(int)(n*100+1e-2)));
	return(0);
}
