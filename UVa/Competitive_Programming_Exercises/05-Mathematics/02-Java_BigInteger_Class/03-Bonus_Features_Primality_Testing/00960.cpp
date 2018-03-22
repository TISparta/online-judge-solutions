#include <bits/stdc++.h>

#define LIM (long long)1e4

using namespace std;

int tc;
bitset <LIM> prime;
long long a, b;
vector <long long> primes;
bool ok;

void sieve(){
	prime[0] = prime[1] = 1;
	for(long long i = 2; i <= LIM; i++){
		if( !prime[i] ){
			for(long long j = i * i; j <= LIM; j += i)
				prime[j] = 1;
			primes.push_back(i);
		}
	}
}

bool isPrime(long long N){
	if(N <= LIM) return !prime[N];
	for(int i = 0; i < (int)primes.size(); i++)
		if(N % primes[i] == 0)
			return false;
	return true;
}

int main(){
	sieve();
	scanf("%d", &tc);
	while(tc--){
		ok = false;
		scanf("%lld %lld", &a, &b);
		a = abs(a), b = abs(b);
		if(isPrime(a * a + b * b)) ok = true;
		else if(a == 0 && isPrime(b) && b % 4 == 3) ok = true;
		else if(b == 0 && isPrime(a) && a % 4 == 3) ok = true;
		printf( ok ? "P\n" : "C\n");
	}
	return(0);
}

