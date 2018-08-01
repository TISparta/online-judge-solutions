#include <bits/stdc++.h>

#define MAX_N 60

using namespace std;

int l,n,v[MAX_N],memo[MAX_N][MAX_N];

int cut(int _left,int _right){
	if(_left+1==_right) return 0;
	if(~memo[_left][_right]) return memo[_left][_right];
	int ans = INT_MAX;
	for(int i=_left+1;i<_right;i++)
		ans = min(ans,cut(_left,i)+cut(i,_right)+(v[_right]-v[_left]));
	return memo[_left][_right] = ans;
}

int main(){
	while(scanf("%d",&l),l){
		memset(memo,-1,sizeof memo);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&v[i]);
		v[n+1] = l;
		printf("The minimum cutting is %d.\n",cut(0,n + 1));
	}
	return(0);
}
