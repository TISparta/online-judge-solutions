#include <bits/stdc++.h>

const long long  LIM = (int)1e6;

using namespace std;

bitset<LIM>prime;
vector<int>p;
int ct,n;

void sieve(){
	prime[0] = 1;
	for(int i=6;i<=LIM;i+=4)
		prime[i] = prime[i-2] = 1;
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
	while(scanf("%d",&n),n){
		ct = 0;
		for(int i=0;i<(int)p.size();i++)
			if(p[i]<=n-p[i] && !prime[n-p[i]])
				ct++;
		printf("%d\n",ct);
	}
	return(0);
}
