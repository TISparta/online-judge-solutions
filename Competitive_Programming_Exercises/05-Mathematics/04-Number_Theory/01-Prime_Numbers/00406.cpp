#include <bits/stdc++.h>

const long long  LIM = 1000;

using namespace std;

bitset<LIM>prime;
vector<int>p;
int n,c,l,ll,rr,pib;

void sieve(){
	p.push_back(1);
	p.push_back(2);
	for(long long i=3;i<LIM;i+=2){
		if(!prime[i]){
			for(long long j=i*i;j<=LIM;j+=2*i)
				prime[j] = 1;
			p.push_back(i);
		}
	}
}

int main(){
	sieve();
	while(scanf("%d %d",&n,&c)==2){
		l = lower_bound(p.begin(),p.end(),n+1)-p.begin();
		l--;
		pib = l&1 ? -1 : -2;
		l >>= 1;
		ll = l-c+1;
		if(ll<0)
			ll = 0;
		rr = ll+2*c+pib<(int)p.size() && p[ll+2*c+pib]<=n ? ll+2*c+pib : 2*l+1;
		while(p[rr]>n || !p[rr])
			rr--;
		printf("%d %d:",n,c);
		for(int i=ll;i<=rr;i++)
			printf(i!=rr ? " %d" : " %d\n",p[i]);
		putchar('\n');
	}
	return(0);
}
